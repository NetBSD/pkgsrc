# $NetBSD: Makefile,v 1.1.1.1 2003/03/19 15:45:27 seb Exp $

DISTNAME=	DB_File-1.806
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	 ${MASTER_SITE_PERL_CPAN:=DB_File/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module to use Berkeley DB version 1 API

USE_BUILDLINK2=	# defined
USE_DB185=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DB_File/.packlist

.include "../../mk/bsd.prefs.mk"
.include "../../databases/db/buildlink2.mk"

# XXX This is a bit ugly...
DB_NAME=		${BUILDLINK_TRANSFORM:Ml\:db\:*:S/l:db:/-l/}
MAKE_ENV+=		DB_NAME=${DB_NAME}
PERL5_LDFLAGS+=		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.db}/lib
PERL5_LDFLAGS+=		-L${BUILDLINK_PREFIX.db}/lib
MAKE_ENV+=		DB_CPPFLAGS=${BUILDLINK_CPPFLAGS.db}
.if ${_NEED_DB2} == "YES"
MAKE_ENV+=		DB_FILE_COMPAT185=1
.else
# We assume that DB 1 is provided by the system and perl5 package picked
# it up.
PKG_SKIP_REASON+=	"The perl package already provides DB_File"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
