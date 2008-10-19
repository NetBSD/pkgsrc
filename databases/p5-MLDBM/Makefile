# $NetBSD: Makefile,v 1.25 2008/10/19 19:17:45 he Exp $
#

DISTNAME=		MLDBM-2.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5mld
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MLDBM/
COMMENT=		Perl5 module for storing arbitrary data in tied hashes

DEPENDS+=	{p5-Data-Dumper>=2.08,perl{,-thread}>=5.6.1nb2}:../../lang/perl5

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MLDBM/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
