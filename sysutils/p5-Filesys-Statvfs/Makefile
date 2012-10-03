# $NetBSD: Makefile,v 1.4 2012/10/03 21:57:41 wiz Exp $
#

DISTNAME=		Filesys-Statvfs-0.82
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		sysutils devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Filesys-Statvfs/
COMMENT=		Perl extension for statvfs() and fstatvfs()

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	MakeMaker

PERL5_PACKLIST=		auto/Filesys/Statvfs/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
