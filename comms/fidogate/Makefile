# $NetBSD: Makefile,v 1.22 2002/11/14 23:55:33 jlam Exp $
#

DISTNAME=	fidogate-4.4.5
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fidogate/}

MAINTAINER=	tv@pobox.com
HOMEPAGE=	http://www.fidogate.org/
COMMENT=	FidoNet (FTN) <-> Internet mail and news gateway

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
MAKE_ENV=		DEBUG="${CFLAGS} -Werror"
BUILDLINK_SETENV.CC=	CC="cc ${_STRIPFLAG_CC}"

INFO_FILES=	fidogate.info

EGDIR=		${PREFIX}/share/examples/fidogate
CONF_FILES=	${EGDIR}/fidogate.conf ${PKG_SYSCONFDIR}/fidogate/fidogate.conf
RCD_SCRIPTS=	fidogate

post-extract:
	@${CP} ${WRKSRC}/examples/orodruin/fidogate.conf \
		${WRKSRC}/fidogate.conf.dist

# This ugliness is because config.make is parsed by both make(1) and
# subst.pl, which does only simplistic substitution.
do-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' -e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},' \
		${WRKSRC}/config.make >${WRKSRC}/config.make.new
	${MV} -f ${WRKSRC}/config.make.new ${WRKSRC}/config.make

pre-build:
	${RM} -f ${WRKSRC}/doc/fidogate.info*
	cd ${WRKSRC}/doc && ${MAKEINFO} --no-split fidogate.texi && \
		${TOUCH} fidogate.txt html/fidogate_toc.html
	${PERL5} ${WRKSRC}/subst.pl -t${WRKSRC} ${WRKSRC}/fidogate.conf.dist \
		>${WRKSRC}/fidogate.conf

pre-install:
	${INSTALL_DATA_DIR} \
		${PKG_SYSCONFDIR}/fidogate \
		${EGDIR} \
		${PREFIX}/lib/fidogate \
		${PREFIX}/lib/fidogate/bin \
		${PREFIX}/share/doc/fidogate \
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
	${INSTALL_DATA} ${WRKSRC}/fidogate.conf ${EGDIR}

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
