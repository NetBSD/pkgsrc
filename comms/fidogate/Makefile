# $NetBSD: Makefile,v 1.16 2001/11/30 17:37:15 jlam Exp $
#

DISTNAME=	fidogate-4.4.4
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.fido.de/pub/fidogate/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.fido.de/fidogate/
COMMENT=	FidoNet (FTN) <-> Internet mail and news gateway

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes

INFO_FILES=	fidogate.info
MAKE_ENV=	DEBUG="${CFLAGS} -Werror" CC="${CC} ${STRIPFLAG}"

post-extract:
	@${CP} ${WRKSRC}/examples/orodruin/fidogate.conf ${WRKSRC}/

# This ugliness is because config.make is parsed by both make(1) and
# subst.pl, which does only simplistic substitution.
do-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		${WRKSRC}/config.make >${WRKSRC}/config.make.new
	${MV} -f ${WRKSRC}/config.make.new ${WRKSRC}/config.make

pre-build:
	${RM} -f ${WRKSRC}/doc/fidogate.info*
	cd ${WRKSRC}/doc && makeinfo --no-split fidogate.texi && \
		${TOUCH} fidogate.txt html/fidogate_toc.html
	${PERL5} ${WRKSRC}/subst.pl -t${WRKSRC} ${WRKSRC}/fidogate.conf \
		>${WRKSRC}/fidogate.conf.dist

pre-install:
	${INSTALL_DATA_DIR} \
		${PREFIX}/etc/fidogate \
		${PREFIX}/lib/fidogate \
		${PREFIX}/lib/fidogate/bin \
		${PREFIX}/share/doc/fidogate \
		${PREFIX}/share/examples/fidogate \
		${PREFIX}/share/fidogate \
		${PREFIX}/share/fidogate/sendmail \
		${PREFIX}/share/fidogate/sendmail/mailer

post-install:
	cd ${WRKSRC}/examples && for f in `${FIND} [m-p]* -type d`; do \
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fidogate/$$f; done
	cd ${WRKSRC}/examples && for f in `${FIND} README [m-p]* -type f`; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/fidogate/$$f; done
	cd ${WRKSRC}/sendmail/mailer && ${INSTALL_DATA} ffx.m4 ftn.m4 \
		${PREFIX}/share/fidogate/sendmail/mailer/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/maintenance/rc.fidogate \
		${PREFIX}/etc/rc.d/fidogate
	${INSTALL_DATA} ${WRKSRC}/doc/fidogate.txt ${PREFIX}/share/doc/fidogate/
	${INSTALL_DATA} ${WRKSRC}/fidogate.conf.dist ${PREFIX}/etc/fidogate/

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
