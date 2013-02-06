# $NetBSD: Makefile,v 1.4 2013/02/06 23:22:44 jperkin Exp $

DISTNAME=		fdm-1.6
PKGREVISION=		1
CATEGORIES=		mail
PKG_REVISION=		1
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fdm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fdm.sourceforge.net/
COMMENT=		Fetch or receive mail and deliver it in various ways
LICENSE=		modified-bsd

INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}
EGDIR=			${PREFIX}/share/examples/fdm
DOCDIR=			${PREFIX}/share/doc/fdm

USE_TOOLS+=		pax
MAKE_ENV+=		PCRE=1

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-patch
SUBST_FILES.files=	Makefile
SUBST_SED.files=	-e "s|@INSTALL_PROGRAM_DIR@|${INSTALL_PROGRAM_DIR}|"
SUBST_SED.files+=	-e "s|@INSTALL_PROGRAM@|${INSTALL_PROGRAM}|"
SUBST_SED.files+=	-e "s|@INSTALL_MAN@|${INSTALL_MAN}|"
SUBST_MESSAGE.files=	Fixing install invocation in Makefile

post-install:
	cd ${WRKSRC}/examples && pax -rwpam . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
