# $NetBSD: Makefile,v 1.19 2015/01/16 09:18:47 taca Exp $

DISTNAME=	ruby-ldap-0.9.16
PKGNAME=	${DISTNAME:S/^ruby-/${RUBY_PKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/alexey-chebotar/ruby-ldap
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
