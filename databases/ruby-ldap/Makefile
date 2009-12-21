# $NetBSD: Makefile,v 1.2 2009/12/21 07:00:02 taca Exp $

DISTNAME=	ruby-ldap-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ldap-${VER}
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/58441/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-ldap/
COMMENT=	LDAP extension module for Ruby
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

VER=		0.9.9

REPLACE_RUBY_DIRS=	example/pr_ctl example/cgi/search.cgi
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
USE_TOOLS+=		pax

CONFIGURE_ARGS+=	--with-openldap2
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}

DOCS=		ChangeLog FAQ README TODO

INSTALLATION_DIRS=	${RUBY_DOCDIR}/ldap ${RUBY_EXAMPLESDIR}/ldap

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_DOCDIR}/ldap
.endfor
	cd ${WRKSRC}/example && pax -rw -pp * ${DESTDIR}${RUBY_EXAMPLESDIR}/ldap

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
