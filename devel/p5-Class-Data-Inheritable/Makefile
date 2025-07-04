# $NetBSD: Makefile,v 1.36 2025/07/04 08:45:21 wiz Exp $

EXTRACT_USING=	gtar	# XXX avoid extended attributes in distfile
			# https://rt.cpan.org/Ticket/Display.html?id=156823

DISTNAME=	Class-Data-Inheritable-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Data-Inheritable
COMMENT=	Inheritable, overridable class data
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Class/Data/Inheritable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
