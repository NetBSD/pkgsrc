# $NetBSD: Makefile,v 1.34 2014/02/14 05:54:51 obache Exp $

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
LICENSE=		original-bsd

BOOTSTRAP_PKG=	yes

GNU_CONFIGURE=		yes
CHECK_PERMS=		no

OPSYSVARS+=		MAKE_ENV
MAKE_ENV.SunOS+=	CPPFLAGS=""

MAKE_ENV+=		CATMAN_SECTION_SUFFIX=${CATMAN_SECTION_SUFFIX:Q}
MAKE_ENV+=		MANINSTALL=${MANINSTALL:Q}

.include "options.mk"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}
	@${RM} -f ${WRKSRC}/INSTALL

# Use mk/readline.builtin.mk to check for an editline library on the
# system.  If we use the system editline library, then use the built-in
# termcap library.
#
CHECK_BUILTIN.editline:=	yes
.include "../../devel/editline/builtin.mk"
CHECK_BUILTIN.editline:=	no

.if !empty(USE_BUILTIN.editline:M[yY][eE][sS])
USE_BUILTIN.termcap?=	yes
.endif

# Check usability of builtin termcap if FETCH_USING=ftp
# to avoid circular dependency with termcap from pkgsrc (devel/ncurses).
CHECK_BUILTIN.termcap:=	yes
.include "../../mk/termcap.builtin.mk"
CHECK_BUILTIN.termcap:=	no

.if !empty(FETCH_USING:Mftp) && !empty(USE_BUILTIN.termcap:M[Nn][Oo])
CONFIGURE_ARGS+=	--disable-editcomplete
.else
.include "../../mk/termcap.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
