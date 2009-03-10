# $NetBSD: Makefile,v 1.1.1.1 2009/03/10 18:57:36 sno Exp $

DISTNAME=	sapnwrfc-0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SAP/PIERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SAP Netweaver RFC support for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c

DEPENDS+=	p5-ExtUtils-MakeMaker>=6.48nb2:../../devel/p5-ExtUtils-MakeMaker
.include "../../devel/sapnwrfcsdk/buildlink3.mk"

MAKE_PARAMS+=		--source ${BUILDLINK_PREFIX.sapnwrfcsdk:Q}

PERL5_PACKLIST=		auto/sapnwrfc/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
