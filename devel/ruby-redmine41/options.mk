# $NetBSD: options.mk,v 1.1 2021/02/28 16:50:02 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.redmine41

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite3
PKG_SUPPORTED_OPTIONS+=		ruby-unicorn
PKG_SUGGESTED_OPTIONS=		mysql ruby-unicorn

PLIST_VARS+=			unicorn

.include "../../mk/bsd.options.mk"

###
### Use mysql, pgsql, or sqlite3 backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${RUBY_PKGPREFIX}-mysql2>=0.5.0<0.6:../../databases/ruby-mysql2
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${RUBY_PKGPREFIX}-pg>=1.1.4:../../databases/ruby-pg
.elif !empty(PKG_OPTIONS:Msqlite3)
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.4.0<1.5:../../databases/ruby-sqlite3
.endif

###
### Use Unicorn web server
###
.if !empty(PKG_OPTIONS:Mruby-unicorn) || make (distinfo) || make (mdi)
DEPENDS+=	${RUBY_PKGPREFIX}-unicorn-[0-9]*:../../www/ruby-unicorn

PLIST.unicorn=	yes

SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-install
SUBST_MESSAGE.prefix=		Setting PREFIX, RUBY_SUFFIX and RM_DIR.
SUBST_FILES.prefix=		${WRKDIR}/unicorn.rb
SUBST_VARS.prefix+=		PREFIX RUBY_SUFFIX RM_DIR

RCD_SCRIPTS+=	redmine41_unicorn${RUBY_SUFFIX}
RCD_SCRIPT_SRC.redmine41_unicorn${RUBY_SUFFIX}=	${FILESDIR}/redmine41_unicorn.sh

CONF_FILES+=	${EGDIR}/unicorn.rb.example \
		${PREFIX}/${RM_DIR}/config/unicorn.rb

PLIST_SRC=	${PLIST_SRC_DFLT} ${RM_PLIST_SRC}

post-extract:
	${CP} ${FILESDIR}/unicorn.rb ${WRKDIR}/unicorn.rb

.PHONY: unicorn-post-install
unicorn-post-install:
	${CP} ${WRKDIR}/unicorn.rb \
		${DESTDIR}${EGDIR}/unicorn.rb.example
	${CP} ${FILESDIR}/Gemfile.local \
		${DESTDIR}${PREFIX}/${RM_DIR}
.endif
.PHONY: unicorn-post-install
unicorn-post-install:
# nothing
