# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:38 obache Exp $
#

DISTNAME=	Template-Plugin-VMethods-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-VMethods/
COMMENT=	Install virtual methods into the Template Toolkit

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty

DEPENDS+=	p5-Template-Toolkit>=2.06:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Plugin/VMethods/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
