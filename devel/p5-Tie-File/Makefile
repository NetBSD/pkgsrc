# $NetBSD: Makefile,v 1.8 2012/03/26 13:11:15 obache Exp $
#

DISTNAME=	Tie-File-0.98
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tfi
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-File/
COMMENT=	Access the lines of a disk file via a Perl array
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tie/File/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
