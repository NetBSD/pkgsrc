# $NetBSD: Makefile,v 1.17 2005/07/13 18:01:19 jlam Exp $
#

DISTNAME=	Jcode-0.88
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5jco
PKGREVISION=	1
CATEGORIES=	converters japanese perl5
MASTER_SITES=	http://openlab.ring.gr.jp/Jcode/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/Jcode/index.html
COMMENT=	Perl5 module for handling various Japanese charsets

DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Jcode/.packlist

pre-configure:
	@cd ${WRKSRC}; ${RM} -f mac_install.pl win_install.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
