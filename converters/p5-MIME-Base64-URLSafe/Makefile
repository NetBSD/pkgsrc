# $NetBSD: Makefile,v 1.11 2016/06/08 19:22:21 wiz Exp $

DISTNAME=	MIME-Base64-URLSafe-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Base64-URLSafe/
COMMENT=	Perl version of Python's URL-safe base64 codec

PERL5_PACKLIST=		auto/MIME/Base64/URLSafe/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
