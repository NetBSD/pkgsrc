# $NetBSD: Makefile,v 1.6 2010/09/10 04:31:57 taca Exp $

DISTNAME=	ruby-ldap-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ldap-${VER}
CATEGORIES=	databases ruby
MASTER_SITES=	http://github.com/alexey-chebotar/ruby-ldap/tarball/${VER}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/alexey-chebotar/ruby-ldap
COMMENT=	LDAP extension module for Ruby
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

VER=		0.9.11

REPLACE_RUBY_DIRS=	example/pr_ctl example/cgi/search.cgi
USE_RUBY_EXTCONF=	yes
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}/alexey-chebotar-ruby-ldap-8541b7b

CONFIGURE_ARGS+=	--with-openldap2
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}

DOCS=		ChangeLog FAQ README TODO

INSTALLATION_DIRS=	${RUBY_DOC}/ldap ${RUBY_EG}/ldap

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/ldap
.endfor
	cd ${WRKSRC}/example && \
		pax -rw -pp * ${DESTDIR}${PREFIX}/${RUBY_EG}/ldap

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
