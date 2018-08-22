# $NetBSD: Makefile,v 1.15 2018/08/22 09:42:56 wiz Exp $

DISTNAME=	CDDB-File-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CDDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CDDB-File/
COMMENT=	Parses a CDDB/freedb data file
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=	auto/CDDB/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
