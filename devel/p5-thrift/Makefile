# $NetBSD: Makefile,v 1.2 2020/08/31 18:09:19 wiz Exp $

PKGREVISION= 1
.include "../../devel/thrift/Makefile.version"

PKGNAME=	p5-${DISTNAME}
CATEGORIES+=	perl5
COMMENT=	Perl bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/perl

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/perl
DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor

PERL5_PACKLIST=		auto/Thrift/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
