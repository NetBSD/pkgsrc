# $NetBSD: Makefile,v 1.7 2007/02/27 09:19:21 wiz Exp $

DISTNAME=	File-MimeInfo-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-MimeInfo/
COMMENT=	Perl module for the freedesktop shared MIME database

DEPENDS+=	p5-File-BaseDir-[0-9]*:../../devel/p5-File-BaseDir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/MimeInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
