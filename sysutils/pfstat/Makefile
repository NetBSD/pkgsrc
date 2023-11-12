# $NetBSD: Makefile,v 1.38 2023/11/12 13:23:36 wiz Exp $

DISTNAME=	pfstat-2.5
PKGREVISION=	17
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.benzedrine.cx/pfstat.html
COMMENT=	Utility to render graphical statistics for PF
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		yacc

MAKE_ENV+=	PF_VERSION=${PF_VERSION:S/.//} NOGCCERROR=yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 ${PKGMANDIR}/cat8 share/examples/pfstat

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	pfstat.8 pfstat.c pfstat.conf.example
SUBST_SED.conf=		-e "s|/etc/pfstat.conf|${PKG_SYSCONFDIR}/pfstat.conf|g"
SUBST_MESSAGE.conf=	Fixing configuration file paths.

post-install:
	${INSTALL_DATA} ${WRKSRC}/pfstat.conf.example ${DESTDIR}${PREFIX}/share/examples/pfstat

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/pf.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
