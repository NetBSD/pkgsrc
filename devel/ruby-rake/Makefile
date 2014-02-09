# $NetBSD: Makefile,v 1.8 2014/02/09 05:21:19 taca Exp $

DISTNAME=	rake-${VERS}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rake/
COMMENT=	Ruby Make
LICENSE=	mit

CONFLICTS+=	 rake-[0-9]*

USE_TOOLS+=	gzip
FIX_PERM=	doc/release_notes/rake-0.7.3.rdoc
VERS=		10.0.4

FILES_SUBST+=	GEM_NAME=${GEM_NAME} RAKE_HACK=${RAKE_HACK} RAKEBIN=${RAKEBIN}
PLIST_SUBST+=	RAKE_HACK=${RAKE_HACK} RAKEBIN=${RAKEBIN}

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../lang/ruby/rubyversion.mk"

OVERRIDE_GEMSPEC+= :executables rake=${RAKEBIN} \
		:files bin/rake=bin/${RAKEBIN} doc/rake.1.gz=doc/rake.1

.if defined(RUBY_RAKE_VERSION)
RAKEBIN=	rake${RUBY_VER}-${PKGVERSION_NOREV}
.  if ${RUBY_RAKE_VERSION} == ${VERS}
RAKE_HACK=	.${PKGVERSION_NOREV}
RAKE_SPEC=	${GEM_HOME}/specifications/${GEM_NAME}.gemspec
.  endif
.endif
RAKEBIN?=	rake${RUBY_VER}

# rake.1.gz has one extra byte at EOF.
pre-configure:
	cd ${WRKSRC}/doc && (gzip -dc rake.1.gz >rake.1 2>/dev/null || ${TRUE})
	cd ${WRKSRC}; ${CHMOD} -x ${FIX_PERM}
	cd ${WRKSRC}/bin && ${MV} rake ${RAKEBIN}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rake.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rake.1
.if !empty(RAKE_HACK)
	${MV} ${DESTDIR}${PREFIX}/${RAKE_SPEC} \
		${DESTDIR}${PREFIX}/${RAKE_SPEC}${RAKE_HACK}
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
