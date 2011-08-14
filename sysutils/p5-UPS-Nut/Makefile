# $NetBSD: Makefile,v 1.2 2011/08/14 14:52:51 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/p5-UPS-Nut/}
COMMENT=		Network UPS Tools perl binding
PKGREVISION=		1
CATEGORIES=		sysutils perl5
PKG_DESTDIR_SUPPORT=	user-destdir
PATCHDIR=

WRKSRC= 		${WRKDIR}/${DISTNAME}/scripts/perl

PERL5_PACKLIST=         auto/UPS/Nut/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
