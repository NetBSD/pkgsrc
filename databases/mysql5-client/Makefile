# $NetBSD: Makefile,v 1.14 2007/12/14 13:36:52 tron Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 5, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes

AUTO_MKDIRS=	yes

post-install:
	cd ${WRKSRC}; for f in mysql.info mysql.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
.for f in huge large innodb-heavy-4G small medium
	${INSTALL_DATA} ${WRKSRC}/support-files/my-${f}.cnf.sh \
		${PREFIX}/share/examples/mysql/my-${f}.cnf
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/manual.chm ${DESTDIR}${PREFIX}/share/doc/mysql/

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
