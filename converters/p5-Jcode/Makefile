# $NetBSD: Makefile,v 1.13 2004/11/12 00:15:48 seb Exp $
#

DISTNAME=	Jcode-0.87
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5jco
CATEGORIES=	converters japanese perl5
MASTER_SITES=	http://openlab.ring.gr.jp/Jcode/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/Jcode/index.html
COMMENT=	Perl5 module for handling various Japanese charsets

DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Jcode/.packlist

pre-configure:
	@cd ${WRKSRC}; ${RM} -f mac_install.pl win_install.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
