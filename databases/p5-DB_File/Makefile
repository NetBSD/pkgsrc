# $NetBSD: Makefile,v 1.7 2004/08/27 06:29:07 jlam Exp $

DISTNAME=	DB_File-1.806
PKGNAME=	p5-${DISTNAME}
SVR$_PKGNAME=	p5dbfi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DB_File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to use Berkeley DB version 1 API

USE_BUILDLINK3=	# defined
USE_DB185=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DB_File/.packlist

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bdb.buildlink3.mk"

# XXX This is a bit ugly...
DB_NAME=		${BUILDLINK_TRANSFORM:Ml\:db\:*:S/l:db:/-l/}
MAKE_ENV+=		DB_NAME=${DB_NAME}
PERL5_LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.db}/lib
PERL5_LDFLAGS+=		-L${BUILDLINK_PREFIX.db}/lib
MAKE_ENV+=		DB_CPPFLAGS=${BUILDLINK_CPPFLAGS.db}
.if ${BDB_TYPE} == "db2"
MAKE_ENV+=		DB_FILE_COMPAT185=1
.else
# We assume that DB 1 is provided by the system and perl5 package picked
# it up.
PKG_SKIP_REASON+=	"The perl package already provides DB_File"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
