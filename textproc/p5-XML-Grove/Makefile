# $NetBSD: Makefile,v 1.21 2011/10/04 15:37:36 hiramatsu Exp $
#

DISTNAME=	XML-Grove-0.46alpha
PKGNAME=	p5-${DISTNAME:S/alpha/.0.1/}
PKGREVISION=	7
SVR4_PKGNAME=	p5xgr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	explorer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Grove/
COMMENT=	Perl 5 module providing simple objects for parsed XML documents
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libxml>=0.0.7:../../textproc/p5-libxml

PERL5_PACKLIST=		auto/XML/Grove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
