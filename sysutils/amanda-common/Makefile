# $NetBSD: Makefile,v 1.8 1999/09/06 19:30:20 bad Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-common-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		addnerd-1.6:../../sysutils/addnerd
ADDUSER_PROG=		${PREFIX}/sbin/addnerd
.elif ${OPSYS} == "SunOS"
ADDUSER_PROG=		useradd
MAKE_ENV+=		CPPFLAGS=-D_LARGEFILE64_SOURCE
.endif

CONFIGURE_ARGS+=	--without-server --without-restore --without-client

CPPFLAGS=		

BUILD_DEFS+=		AMANDA_USER AMANDA_SMB AMANDA_VAR

pre-install:
	case `${GREP} -c '^${AMANDA_USER}:' /etc/passwd || ${TRUE}` in	\
	0)								\
		${SETENV} ${MAKE_ENV} ${ADDUSER_PROG} -g ${AMANDA_GROUP} ${AMANDA_USER} \
		;;							\
	esac

.include "../../mk/bsd.pkg.mk"
