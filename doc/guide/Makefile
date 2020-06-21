# $NetBSD: Makefile,v 1.65 2020/06/21 10:41:36 rillig Exp $

DISTNAME=		pkgsrc-guide-${PKGVERSION}
CATEGORIES=		# empty
MASTER_SITES=		${MASTER_SITE_LOCAL}
DISTFILES=		htdocs-share-20200621.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/docs/pkgsrc/
COMMENT=		The pkgsrc guide

# To regenerate pkgsrc/doc/pkgsrc.{html,txt} and
# htdocs/docs/pkgsrc, just run "make regen".

PKGVERSION!=		date '+%Y%m%d'
DIST_SUBDIR=		${PKGBASE}
USE_LANGUAGES=		# empty
MAKE_ENV+=		SED=${SED:Q}

PLIST_VARS=		ascii html pdf epub

DOCDIR=			${PREFIX}/share/doc/pkgsrc
.if exists(/usr/cvs/htdocs)
HTDOCSDIR?=		/usr/cvs/htdocs
.endif
HTDOCSDIR?=		${.CURDIR}/../../../htdocs

BUILD_DEFS+=		OUTPUTS
OUTPUTS?=		lint html html-split ascii ps pdf

INSTALLATION_DIRS=	${DOCDIR}

SUBST_CLASSES+=		docbook45
SUBST_STAGE.docbook45=	pre-configure
SUBST_FILES.docbook45=	${WRKDIR}/htdocs/share/xml/*
SUBST_SED.docbook45=	-e 's,V4\.2,V4.5,'
SUBST_SED.docbook45+=	-e 's,/4\.2/,/4.5/,'

.if defined(OUTPUTS)
.  if !empty(OUTPUTS:Mascii)
# the html is needed to build the ascii version.
OUTPUTS+=		html
PLIST.ascii=		yes
.  endif

.  if !empty(OUTPUTS:Mhtml) || !empty(OUTPUTS:Mhtml-split)
PLIST.html=		yes
.endif

.  if !empty(OUTPUTS:Mpdf)
PLIST.pdf=		yes
.endif

.  if !empty(OUTPUTS:Mepub)
PLIST.epub=		yes
.endif

# only override the Makefile.common default if it is explicitly set
_GUIDE_OUTPUTS=		${OUTPUTS}
.endif

.include "Makefile.common"

# The source files are only symlinked into the WRKSRC, so that they can
# be easily modified, should the "lint" phase fail.
pre-extract:
	${MKDIR} ${WRKSRC}
	${LN} -s ${FILESDIR}/* ${WRKSRC}

pre-configure: generate-help-topics
generate-help-topics: .PHONY
	${RUN} ${MAKE} help topic=:index > ${WRKSRC}/help-topics.data
	${RUN} cd ${WRKSRC} && env PKGSRCDIR=${PKGSRCDIR} python fill-placeholders.py *.xml

do-build:
.for _output_ in ${OUTPUTS}
	@${ECHO} "-----> Building ${_output_} output"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${_output_}
.endfor

post-build:
	@${RM} -f ${WRKSRC}/pkgsrc.tmp.html
	${RUN} cd ${WRKSRC};						\
	${GREP} 'idm[0-9][0-9][0-9][0-9][0-9]' ./*.html || exit 0;	\
	${FAIL_MSG} "[post-build] HTML files contain generated IDs."
	# These IDs generate unnecessary changes to the generated files,
	# when they are committed to pkgsrc/doc/ and htdocs.

do-install:
.if !empty(OUTPUTS:Mhtml) || !empty(OUTPUTS:Mhtml-split)
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/htdocs/global.css ${DESTDIR}${DOCDIR}
.endif
.if !empty(OUTPUTS:Mascii)
	${INSTALL_DATA} ${WRKSRC}/pkgsrc.txt ${DESTDIR}${DOCDIR}
.endif
.if !empty(OUTPUTS:Mpdf)
	${INSTALL_DATA} ${WRKSRC}/pkgsrc.ps ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/pkgsrc.pdf ${DESTDIR}${DOCDIR}
.endif

# install the single-file HTML and ascii output into the pkgsrc doc/
# directory, for distribution with pkgsrc.
#
# note that this uses ${CP} and not ${INSTALL_DATA} because the files
# stay in the development directories and have nothing to do with
# the permissions or ownership of installed files.
#
install-doc: build
	${CP} ${WRKSRC}/pkgsrc.html ${PKGSRCDIR}/doc
	${CP} ${WRKSRC}/pkgsrc.txt ${PKGSRCDIR}/doc

install-htdocs: build
	cd ${WRKSRC} && ${CP} pkgsrc.txt pkgsrc.pdf pkgsrc.ps *.html	\
		${HTDOCSDIR}/docs/pkgsrc

.PHONY: regen cvs-update regen-doc regen-htdocs
regen: cvs-update regen-doc regen-htdocs

regen: cvs-update

cvs-update:
	cvs -q update -dP

regen-doc: build
	@${STEP_MSG} "Updating the files in pkgsrc/doc"
	cd .. && cvs update pkgsrc.*
	${MAKE} ${MAKEFLAGS} install-doc
	@${STEP_MSG} "Committing the files in pkgsrc/doc"
	cd .. && cvs commit -m "doc/pkgsrc.*: regen" pkgsrc.*

regen-htdocs: build
	@${STEP_MSG} "Updating the files in htdocs"
	cd ${HTDOCSDIR}/docs/pkgsrc && cvs update
	${MAKE} ${MAKEFLAGS} install-htdocs
	@${STEP_MSG} "Committing the files in htdocs"
	cd ${HTDOCSDIR}/docs/pkgsrc && cvs commit -m "regen"

do-lint:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} lint

DETAB_PROGRAM= \
	if (/<programlisting>/ .. /<\/programlisting>/) {		\
		while (/(.*?)\t(.*)/s) {				\
			my $$filler = " " x (8 - (length($$1) % 8));	\
			$$_ = "$$1$$filler$$2";				\
		}							\
	}

# remove tabulators from the <programlisting> tags.
# TeX does not like them.
.PHONY: detab
detab:
	cd ${FILESDIR} &&						\
	perl -p -i".detab.tmp" -e '${DETAB_PROGRAM}' *.xml &&		\
	${RM} -f *.xml.detab.tmp

# Generates a new htdocs-share-*.tar.gz archive from the current
# contents of the htdocs directory. To make it available, it should
# be copied to ftp.NetBSD.org:/pub/pkgsrc/distfiles/LOCAL_PORTS/, i.e.:
#
# % scp htdocs-share-*.tar.gz ftp.NetBSD.org:/pub/pkgsrc/distfiles/LOCAL_PORTS/
# [... adjust DISTFILES variable ...]
# % make makesum
#
.PHONY: htdocs-share
htdocs-share:
	cd ${HTDOCSDIR}							\
	&& ${PAX} -wz -f ${.CURDIR}/htdocs-share-${PKGVERSION}.tar.gz	\
		-s ',^,htdocs/,'					\
		global.css share

PYTHON_FOR_BUILD_ONLY=	tool
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
