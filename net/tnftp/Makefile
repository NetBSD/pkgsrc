# $NetBSD: Makefile,v 1.23 2008/03/06 04:45:58 jlam Exp $

DISTNAME=		tnftp-20070806
SVR4_PKGNAME=		tnftp
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

# distfile obtained from: ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp

CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS+=		lukemftp-[0-9]*

MAINTAINER=		lukem@NetBSD.org
COMMENT=		The enhanced FTP client in NetBSD

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
NO_CHECKSUM=		yes

OPSYSVARS+=		MAKE_ENV
MAKE_ENV.SunOS+=	CPPFLAGS=""

.include "options.mk"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}
	@${RM} -f ${WRKSRC}/INSTALL

# Use readline/builtin.mk to check for an editline library on the
# system.  If we use the system editline library, then use the built-in
# termcap library.
#
CHECK_BUILTIN.readline:=	yes
.include "../../devel/readline/builtin.mk"
CHECK_BUILTIN.readline:=	no

.if !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS])
USE_BUILTIN.termcap=	yes
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
