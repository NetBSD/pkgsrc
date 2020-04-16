# $NetBSD: Makefile,v 1.30 2020/04/16 13:34:56 mef Exp $

DISTNAME=	OLE-Storage_Lite-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OLE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/OLE-Storage_Lite
COMMENT=	Module for reading and writing OLE-Structured files

DEPENDS+=		p5-IO-stringy>=2.101:../../devel/p5-IO-stringy

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/OLE/Storage_Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
