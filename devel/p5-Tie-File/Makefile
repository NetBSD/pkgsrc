# $NetBSD: Makefile,v 1.5 2010/08/21 16:34:40 seb Exp $
#

DISTNAME=	Tie-File-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5tfi
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-File/
COMMENT=	Access the lines of a disk file via a Perl array

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tie/File/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
