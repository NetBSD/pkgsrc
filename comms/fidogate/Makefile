# $NetBSD: Makefile,v 1.32 2004/04/24 01:59:00 tv Exp $
#

DISTNAME=	fidogate-4.4.5
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fidogate/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.fidogate.org/
COMMENT=	FidoNet (FTN) <-> Internet mail and news gateway

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
MAKE_ENV=		DEBUG="${CFLAGS} -Werror"
BUILDLINK_SETENV.CC=	CC="cc ${_STRIPFLAG_CC}"

USE_MAKEINFO=	YES
INFO_FILES=	fidogate.info

EGDIR=		${PREFIX}/share/examples/fidogate
CONF_FILES=	${EGDIR}/fidogate.conf ${PKG_SYSCONFDIR}/fidogate/fidogate.conf
RCD_SCRIPTS=	fidogate

PKG_USERS=	news:news::Network\\ News:/var/spool/news:${NOLOGIN}
PKG_GROUPS=	news

post-extract:
	@${CP} ${WRKSRC}/examples/orodruin/fidogate.conf \
		${WRKSRC}/fidogate.conf.dist

# This ugliness is because config.make is parsed by both make(1) and
# subst.pl, which does only simplistic substitution.
do-configure:
	@${MV} -f ${WRKSRC}/config.make ${WRKSRC}/config.make.orig
	@${SED} ${FILES_SUBST_SED} \
		${WRKSRC}/config.make.orig > ${WRKSRC}/config.make

pre-build:
	${RM} -f ${WRKSRC}/doc/fidogate.info*
	cd ${WRKSRC}/doc && ${MAKEINFO} --no-split fidogate.texi && \
		${TOUCH} fidogate.txt html/fidogate_toc.html
	${PERL5} ${WRKSRC}/subst.pl -t${WRKSRC} ${WRKSRC}/fidogate.conf.dist \
		>${WRKSRC}/fidogate.conf

pre-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/fidogate
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/lib/fidogate
	${INSTALL_DATA_DIR} ${PREFIX}/lib/fidogate/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fidogate
	${INSTALL_DATA_DIR} ${PREFIX}/share/fidogate
	${INSTALL_DATA_DIR} ${PREFIX}/share/fidogate/sendmail
	${INSTALL_DATA_DIR} ${PREFIX}/share/fidogate/sendmail/mailer

post-install:
	cd ${WRKSRC}/examples && for f in `${FIND} [m-p]* -type d -print`; do \
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fidogate/$$f; done
	cd ${WRKSRC}/examples && for f in `${FIND} README [m-p]* -type f -print`; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/fidogate/$$f; done
	cd ${WRKSRC}/sendmail/mailer && ${INSTALL_DATA} ffx.m4 ftn.m4 \
		${PREFIX}/share/fidogate/sendmail/mailer
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/maintenance/rc.fidogate \
		${PREFIX}/etc/rc.d/fidogate
	${INSTALL_DATA} ${WRKSRC}/doc/fidogate.txt ${PREFIX}/share/doc/fidogate
	${INSTALL_DATA} ${WRKSRC}/fidogate.conf ${EGDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
