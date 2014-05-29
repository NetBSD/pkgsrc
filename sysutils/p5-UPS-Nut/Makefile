# $NetBSD: Makefile,v 1.8 2014/05/29 23:37:31 wiz Exp $

.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/p5-UPS-Nut/}
COMMENT=		Network UPS Tools perl binding
PKGREVISION=		4
CATEGORIES=		sysutils perl5
PATCHDIR=		${.CURDIR}/patches

WRKSRC= 		${WRKDIR}/${DISTNAME}/scripts/perl

PERL5_PACKLIST=         auto/UPS/Nut/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
