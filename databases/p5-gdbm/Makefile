# $NetBSD: Makefile,v 1.42 2014/05/29 23:35:31 wiz Exp $

.include "../../lang/perl5/Makefile.common"
PKGNAME=	p5-${DISTNAME:S/perl/gdbm/}
PKGREVISION=	1
SVR4_PKGNAME=	p5gdm
CATEGORIES=	databases perl5

#PATCHDIR=	${.CURDIR}/../../lang/perl5/patches
DISTINFO_FILE=	${.CURDIR}/../../lang/perl5/distinfo

COMMENT=	Perl interface to gdbm - GNU database manager
LICENSE=	${PERL5_LICENSE}

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

PERL5_PACKLIST=		auto/GDBM_File/.packlist

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
