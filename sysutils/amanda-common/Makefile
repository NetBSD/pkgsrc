# $NetBSD: Makefile,v 1.7 1999/08/20 06:21:29 garbled Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-common-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		addnerd-1.6:../../sysutils/addnerd
ADDUSER_PROG=		${PREFIX}/sbin/addnerd
AMANDA_GROUP=		operator
.elif ${OPSYS} == "SunOS"
ADDUSER_PROG=		useradd
MAKE_ENV+=		CPPFLAGS=-D_LARGEFILE64_SOURCE
AMANDA_GROUP=		sysadmin
.endif

AMANDA_USER?=		backup
AMANDA_VAR?=		/var/amanda

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} \
			--with-group=${AMANDA_GROUP} \
			--with-owner=root \
			--with-mmap --with-amandahosts \
			--with-includes=${PREFIX}/include \
			--with-libraries=${PREFIX}/lib \
			--localstatedir=${AMANDA_VAR} \
			--with-gnutar-listdir=${AMANDA_VAR}/gnutar-lists \
			--with-dump-honor-nodump \
			--without-server --without-restore --without-client

CPPFLAGS=		

BUILD_DEFS+=		AMANDA_USER AMANDA_SMB AMANDA_VAR

pre-install:
	case `${GREP} -c '^${AMANDA_USER}:' /etc/passwd || ${TRUE}` in	\
	0)								\
		${SETENV} ${MAKE_ENV} ${ADDUSER_PROG} -g ${AMANDA_GROUP} ${AMANDA_USER} \
		;;							\
	esac

.include "../../mk/bsd.pkg.mk"
