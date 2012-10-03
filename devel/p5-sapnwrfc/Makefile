# $NetBSD: Makefile,v 1.6 2012/10/03 21:55:53 wiz Exp $

DISTNAME=	sapnwrfc-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SAP/PIERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/sapnwrfc/
COMMENT=	SAP Netweaver RFC support for Perl
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c

.include "../../devel/sapnwrfcsdk/buildlink3.mk"

MAKE_PARAMS+=		--source ${BUILDLINK_PREFIX.sapnwrfcsdk:Q}

PERL5_PACKLIST=		auto/sapnwrfc/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
