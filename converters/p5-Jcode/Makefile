# $NetBSD: Makefile,v 1.37 2019/08/11 13:18:13 wiz Exp $

DISTNAME=	Jcode-2.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	converters japanese perl5
MASTER_SITES=	http://openlab.ring.gr.jp/Jcode/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/Jcode/index.html
COMMENT=	Perl5 module for handling various Japanese charsets

#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64>=2.1}:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Jcode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
