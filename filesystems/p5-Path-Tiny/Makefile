# $NetBSD: Makefile,v 1.42 2025/07/04 08:47:09 wiz Exp $

EXTRACT_USING=  gtar	# XXX avoid extended attributes in distfile
			# https://rt.cpan.org/Ticket/Display.html?id=156823

DISTNAME=	Path-Tiny-0.148
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-Tiny
COMMENT=	Perl5 file path utility
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/Path/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
