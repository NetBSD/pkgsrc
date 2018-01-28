# $NetBSD: Makefile,v 1.48 2018/01/28 20:10:44 wiz Exp $

PKGREVISION= 3
.include "../../lang/perl5/Makefile.common"
PKGNAME=	p5-${DISTNAME:S/perl/gdbm/}
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
