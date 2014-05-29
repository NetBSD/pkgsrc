# $NetBSD: Makefile,v 1.19 2014/05/29 23:35:54 wiz Exp $

DISTNAME=	File-MimeInfo-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-MimeInfo/
COMMENT=	Perl module for the freedesktop shared MIME database
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-File-BaseDir-[0-9]*:../../devel/p5-File-BaseDir
DEPENDS+=	p5-File-DesktopEntry-[0-9]*:../../devel/p5-File-DesktopEntry
DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info

PERL5_PACKLIST=		auto/File/MimeInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
