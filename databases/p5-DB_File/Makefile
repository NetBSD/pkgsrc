# $NetBSD: Makefile,v 1.11 2004/11/15 18:42:04 jlam Exp $

DISTNAME=	DB_File-1.806
PKGNAME=	p5-${DISTNAME}
SVR$_PKGNAME=	p5dbfi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DB_File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to use Berkeley DB version 1 API

USE_BUILDLINK3=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DB_File/.packlist

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bdb.buildlink3.mk"

MAKE_ENV+=	DB_NAME="${BDB_LIBS}"
MAKE_ENV+=	DB_FILE_INCLUDE="${BDBBASE}/${BUILDLINK_INCDIRS.${BDB_TYPE}}"
MAKE_ENV+=	DB_FILE_LIB="${BDBBASE}/lib"
MAKE_ENV+=	DB_FILE_COMPAT185=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
