# $NetBSD: Makefile,v 1.50 2006/02/05 23:08:27 joerg Exp $
#

DISTNAME=	fidogate-4.4.10
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fidogate/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.fidogate.org/
COMMENT=	FidoNet (FTN) <-> Internet mail and news gateway

USE_TOOLS+=		gmake perl:run
MAKE_ENV+=		DEBUG="${CFLAGS} -Werror"
BUILDLINK_SETENV.CC=	CC="cc ${_STRIPFLAG_CC}"

USE_MAKEINFO=	YES
INFO_FILES=	fidogate.info

EGDIR=		${PREFIX}/share/examples/fidogate
CONF_FILES=	${EGDIR}/fidogate.conf ${PKG_SYSCONFDIR}/fidogate/fidogate.conf
RCD_SCRIPTS=	fidogate

PKG_USERS=	news:news::Network\ News:/var/spool/news:${NOLOGIN}
PKG_GROUPS=	news

NO_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config.make
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	@${CP} ${WRKSRC}/examples/orodruin/fidogate.conf \
		${WRKSRC}/fidogate.conf.dist

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
		${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/fidogate
	${INSTALL_DATA} ${WRKSRC}/doc/fidogate.txt ${PREFIX}/share/doc/fidogate
	${INSTALL_DATA} ${WRKSRC}/fidogate.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
