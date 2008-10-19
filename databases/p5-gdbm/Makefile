# $NetBSD: Makefile,v 1.32 2008/10/19 19:17:45 he Exp $

DISTNAME=	perl-5.8.8
PKGNAME=	p5-gdbm-1.08
PKGREVISION=	1
SVR4_PKGNAME=	p5gdm
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S,/modules/by-module/$,/src/,}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl interface to gdbm - GNU database manager

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

PERL5_PACKLIST=		auto/GDBM_File/.packlist

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
