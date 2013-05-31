# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:20 wiz Exp $

DISTNAME=	File-Save-Home-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Save-Home/
COMMENT=	Place file safely under user home directory
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-String-PerlIdentifier-[0-9]*:../../devel/p5-String-PerlIdentifier

PERL5_PACKLIST=		auto/File/Save/Home/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
