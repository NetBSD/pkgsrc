# $NetBSD: Makefile,v 1.17 2011/01/13 13:39:25 wiz Exp $

DISTNAME=	pfstat-2.3
PKGREVISION=	4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/pfstat.html
COMMENT=	Utility to render graphical statistics for PF

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
MAKE_ENV+=	PF_VERSION=${PF_VERSION:S/.//} NOGCCERROR=yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/examples/pfstat

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	pfstat.8 pfstat.c pfstat.conf.example
SUBST_SED.conf=		-e "s|/etc/pfstat.conf|${PREFIX}/etc/pfstat.conf|g"
SUBST_MESSAGE.conf=	Fixing configuration file paths.

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/pfstatd && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/pfstat.conf.example ${DESTDIR}${PREFIX}/share/examples/pfstat
	${INSTALL_PROGRAM} ${WRKSRC}/pfstatd/pfstatd ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstatd/pfstatd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/pf.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
