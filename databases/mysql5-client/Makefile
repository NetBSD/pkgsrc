# $NetBSD: Makefile,v 1.16 2008/01/18 05:06:27 tnn Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		2
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
