# $NetBSD: Makefile,v 1.9 2025/01/06 21:49:07 ktnb Exp $

DISTNAME=	realboy-0.2.2
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=realboy/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://realboyemulator.wordpress.com/
COMMENT=	Complete, fast, yet accurate Game Boy/Game Boy Color emulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	share/doc/realboy

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_MKPIE} == "yes"
CONFIGURE_ARGS+=	--disable-asm
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/realboy

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
