# $NetBSD: Makefile,v 1.18.4.1 2008/09/23 11:15:53 tron Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		1
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL 5, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-extra-tools
CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=	--enable-thread-safe-client
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes

AUTO_MKDIRS=	yes

REPLACE_PERL=	scripts/mysql_convert_table_format.sh \
		scripts/mysql_explain_log.sh \
		scripts/mysql_tableinfo.sh \
		scripts/mysqldumpslow.sh \
		scripts/mysqlhotcopy.sh

post-install:
	cd ${WRKSRC}; for f in mysql.info mysql.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done
.for f in huge large innodb-heavy-4G small medium
	${INSTALL_DATA} ${WRKSRC}/support-files/my-${f}.cnf.sh \
		${DESTDIR}${PREFIX}/share/examples/mysql/my-${f}.cnf
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/manual.chm \
		${DESTDIR}${PREFIX}/share/doc/mysql/

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
