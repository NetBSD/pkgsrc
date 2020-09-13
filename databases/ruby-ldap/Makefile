# $NetBSD: Makefile,v 1.24 2020/09/13 15:11:07 taca Exp $

DISTNAME=	ruby-ldap-0.9.20
PKGNAME=	${DISTNAME:S/^ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexey-chebotar/ruby-ldap
COMMENT=	LDAP extension module for Ruby
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	--with-openldap2
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}

GEM_CLEANBUILD=	Makefile *.o *.time ldap.${RUBY_DLEXT} mkmf.log
GEM_CLEANBUILD_EXTENSIONS=	ldap/control.rb ldap/ldif.rb ldap/schema.rb

# for LDAP_OPT_X_SASL_NOCANON
BUILDLINK_API_DEPENDS.openldap-client+=	openldap-client>=2.4.14
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
