# $NetBSD: Makefile,v 1.14 2001/05/02 08:22:28 jlam Exp $
#

.include "../../databases/mysql-client/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-client-/}
COMMENT=		MySQL, a free SQL database (client)

INFO_FILES=		mysql.info

CONFIGURE_ARGS+=	--without-server

.if exists(/usr/include/readline.h) || exists(/usr/include/readline/readline.h)
CONFIGURE_ENV+=		readline_lib="edit"
.else
DEPENDS+=		readline>=4.0:../../devel/readline
CPPFLAGS+=		-I${LOCALBASE}/include
.endif

# The compilation looks for <readline/readline.h>, so make sure
# /usr/include/readline.h may be accessed that way if it's the readline
# header available on the system.
#
.if exists(/usr/include/readline.h)
CPPFLAGS+=		-I${WRKDIR}

pre-build:
	${RM} -f ${WRKDIR}/readline
	${LN} -sf /usr/include ${WRKDIR}/readline
.endif

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
