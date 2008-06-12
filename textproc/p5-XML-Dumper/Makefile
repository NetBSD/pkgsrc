# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:50 joerg Exp $

DISTNAME=	XML-Dumper-0.81
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xdu
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Simple/
COMMENT=	Perl to XML structure input/output engine

DEPENDS+=	p5-XML-Parser>=2.16:../../textproc/p5-XML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
