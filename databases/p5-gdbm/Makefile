# $NetBSD: Makefile,v 1.15 2002/11/01 16:34:36 wiz Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
PKGREVISION=		1
SVR4_PKGNAME=		p5gdm
CATEGORIES+=		perl5

MAINTAINER=		packages@netbsd.org
COMMENT=		perl interface to gdbm - GNU database manager

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

.include "../../databases/gdbm/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
