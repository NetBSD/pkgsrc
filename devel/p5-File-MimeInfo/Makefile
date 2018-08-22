# $NetBSD: Makefile,v 1.29 2018/08/22 09:44:01 wiz Exp $

DISTNAME=	File-MimeInfo-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-MimeInfo/
COMMENT=	Perl module for the freedesktop shared MIME database
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-BaseDir-[0-9]*:../../devel/p5-File-BaseDir
DEPENDS+=	p5-File-DesktopEntry-[0-9]*:../../devel/p5-File-DesktopEntry
DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info
# for make test (when t/05_more.t 'require (File::DesktopEntry);'
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=		auto/File/MimeInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
