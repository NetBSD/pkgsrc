# $NetBSD: Makefile,v 1.34.6.1 2014/11/06 10:15:58 tron Exp $

DISTNAME=		tnftp-20141104
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

# distfile obtained from: ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp

CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS+=		lukemftp-[0-9]*

MAINTAINER=		lukem@NetBSD.org
COMMENT=		The enhanced FTP client in NetBSD
LICENSE=		original-bsd

BOOTSTRAP_PKG=		yes

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

post-install:
	${MV} -f ${DESTDIR}${PREFIX}/bin/tnftp ${DESTDIR}${PREFIX}/bin/ftp
	${MV} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tnftp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ftp.1


.include "../../mk/bsd.pkg.mk"
