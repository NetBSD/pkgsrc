# $NetBSD: Makefile,v 1.53 2020/06/02 08:23:41 adam Exp $

DISTNAME=	redmine-4.0.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	3
PREV_PKGPATH=	devel/redmine
CATEGORIES=	devel
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

GEMS_DISTFILES+=	actioncable-5.2.4.2.gem actionmailer-5.2.4.2.gem
GEMS_DISTFILES+=	actionpack-5.2.4.2.gem actionpack-xml_parser-2.0.1.gem
GEMS_DISTFILES+=	actionview-5.2.4.2.gem activejob-5.2.4.2.gem
GEMS_DISTFILES+=	activemodel-5.2.4.2.gem activerecord-5.2.4.2.gem
GEMS_DISTFILES+=	activestorage-5.2.4.2.gem activesupport-5.2.4.2.gem
GEMS_DISTFILES+=	addressable-2.7.0.gem arel-9.0.0.gem builder-3.2.3.gem
GEMS_DISTFILES+=	capybara-2.18.0.gem childprocess-2.0.0.gem
GEMS_DISTFILES+=	concurrent-ruby-1.1.5.gem crass-1.0.4.gem 
GEMS_DISTFILES+=	css_parser-1.7.0.gem csv-3.0.9.gem docile-1.1.5.gem
GEMS_DISTFILES+=	erubi-1.8.0.gem globalid-0.4.2.gem
GEMS_DISTFILES+=	htmlentities-4.3.4.gem i18n-0.7.0.gem json-2.2.0.gem
GEMS_DISTFILES+=	loofah-2.2.3.gem mail-2.7.1.gem marcel-0.3.3.gem
GEMS_DISTFILES+=	metaclass-0.0.4.gem method_source-0.9.2.gem
GEMS_DISTFILES+=	mimemagic-0.3.4.gem mini_mime-1.0.2.gem
GEMS_DISTFILES+=	mini_portile2-2.4.0.gem minitest-5.11.3.gem
GEMS_DISTFILES+=	mocha-1.9.0.gem net-ldap-0.16.2.gem
GEMS_DISTFILES+=	nio4r-2.5.1.gem nokogiri-1.10.7.gem
GEMS_DISTFILES+=	public_suffix-4.0.1.gem puma-3.12.1.gem rack-2.0.7.gem
GEMS_DISTFILES+=	rack-openid-1.4.2.gem rack-test-1.1.0.gem
GEMS_DISTFILES+=	rails-5.2.4.2.gem rails-dom-testing-2.0.3.gem
GEMS_DISTFILES+=	rails-html-sanitizer-1.0.4.gem railties-5.2.4.2.gem
GEMS_DISTFILES+=	rake-12.3.3.gem rbpdf-1.19.8.gem
GEMS_DISTFILES+=	rbpdf-font-1.19.1.gem redcarpet-3.4.0.gem
GEMS_DISTFILES+=	request_store-1.0.5.gem rmagick-2.16.0.gem
GEMS_DISTFILES+=	roadie-3.5.0.gem roadie-rails-1.3.0.gem rouge-3.3.0.gem
GEMS_DISTFILES+=	ruby-openid-2.9.2.gem rubyzip-1.2.3.gem
GEMS_DISTFILES+=	selenium-webdriver-3.142.4.gem simplecov-0.14.1.gem
GEMS_DISTFILES+=	simplecov-html-0.10.2.gem sprockets-3.7.2.gem
GEMS_DISTFILES+=	sprockets-rails-3.2.1.gem thor-0.20.3.gem
GEMS_DISTFILES+=	thread_safe-0.3.6.gem tzinfo-1.2.6.gem
GEMS_DISTFILES+=	websocket-driver-0.7.1.gem
GEMS_DISTFILES+=	websocket-extensions-0.1.4.gem
GEMS_DISTFILES+=	yard-0.9.20.gem

PRINT_PLIST_AWK+=	/^${GEM_EXTSDIR:S|/|\\/|g}/ \
				{ gsub(/${GEM_EXTSDIR:S|/|\\/|g}/, "$${GEM_EXTSDIR}") }
PRINT_PLIST_AWK+=	/^${GEM_HOME:S|/|\\/|g}/ \
				{ gsub(/${GEM_HOME:S|/|\\/|g}/, "$${GEM_HOME}") }
PRINT_PLIST_AWK+=	/^${RM_DIR:S|/|\\/|g}/ { gsub(/^${RM_DIR:S|/|\\/|g}/, "$${RM_DIR}"); }

RUBY_VERSIONS_ACCEPTED=	25 26

.include "../../lang/ruby/rubyversion.mk"

PLIST_SUBST+=		RM_DIR=${RM_DIR:Q}

DISTFILES+=	${DEFAULT_DISTFILES}

.include "options.mk"

.for gem in ${GEMS_DISTFILES}
DISTFILES+=	${gem}
SITES.${gem}=	https://rubygems.org/downloads/
.endfor

WRKSRC=		${WRKDIR}
RM_DIR=		share/${RUBY_PKGPREFIX}-redmine

USE_TOOLS+=	bash:run pax pkg-config

REPLACE_RUBY+=	builder-3.2.3/lib/*.rb builder-3.2.3/lib/builder/blankslate.rb
REPLACE_RUBY+=	builder-3.2.3/lib/builder/x*.rb builder-3.2.3/rakelib/tags.rake
REPLACE_RUBY+=	builder-3.2.3/test/p*.rb builder-3.2.3/test/t*.rb
REPLACE_RUBY+=	json-2.2.0/install.rb json-2.2.0/tests/json_generator_test.rb
REPLACE_RUBY+=	json-2.2.0/tools/server.rb loofah-2.2.3/benchmark/benchmark.rb
REPLACE_RUBY+=	mimemagic-0.3.4/script/generate-mime.rb
REPLACE_RUBY+=	mini_mime-1.0.2/bin/console mocha-1.9.0/bin/build-matrix
REPLACE_RUBY+=	nio4r-2.5.1/examples/echo_server.rb nokogiri-1.10.7/bin/nokogiri
REPLACE_RUBY+=	public_suffix-4.0.1/bin/console
REPLACE_RUBY+=	puma-3.12.1/bin/puma-wild puma-3.12.1/bin/puma
REPLACE_RUBY+=	puma-3.12.1/bin/pumactl rack-2.0.7/bin/rackup
REPLACE_RUBY+=	rack-2.0.7/test/cgi/rackup_stub.rb rack-2.0.7/test/cgi/test
REPLACE_RUBY+=	rack-2.0.7/test/cgi/test.fcgi railties-5.2.4.2/exe/rails
REPLACE_RUBY+=	raindrops-0.19.1/examples/linux-listener-stats.rb
REPLACE_RUBY+=	rake-12.3.3/bin/bundle rake-12.3.3/bin/console
REPLACE_RUBY+=	rake-12.3.3/bin/rake rake-12.3.3/bin/rdoc
REPLACE_RUBY+=	rake-12.3.3/bin/rubocop rake-12.3.3/exe/rake
REPLACE_RUBY+=	rbpdf-1.19.8/test/test_helper.rb
REPLACE_RUBY+=	rbpdf-font-1.19.1/test/test_helper.rb
REPLACE_RUBY+=	redcarpet-3.4.0/bin/redcarpet ${DISTNAME}/bin/*
REPLACE_RUBY+=	${DISTNAME}/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	${DISTNAME}/extra/svn/reposman.rb
REPLACE_RUBY+=	${DISTNAME}/public/dispatch.fcgi.example
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/adaptive_threshold.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/add_noise.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/affine.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/affine_transform.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/arc.rb rmagick-2.16.0/doc/ex/arcpath.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/average.rb rmagick-2.16.0/doc/ex/axes.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/bilevel_channel.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/blur_image.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/border.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/bounding_box.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/cbezier*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/channel.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/charcoal.rb rmagick-2.16.0/doc/ex/chop.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/circle.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/clip_path.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/coalesce.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/color*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/composite.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/composite_layers.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/contrast.rb rmagick-2.16.0/doc/ex/crop.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/crop_with_gravity.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/cycle_colormap.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/dissolve.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/drawcomp.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/drop_shadow.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/edge.rb rmagick-2.16.0/doc/ex/ellipse.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/emboss.rb rmagick-2.16.0/doc/ex/enhance.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/equalize.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/evenodd.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/fill_pattern.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/flatten_images.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/flip.rb rmagick-2.16.0/doc/ex/flop.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/font_styles.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/fonts.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/frame.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/gaussian_blur.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/get_*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/gradientfill.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/grav.rb rmagick-2.16.0/doc/ex/gravity.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/hatchfill.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/implode.rb rmagick-2.16.0/doc/ex/level.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/line.rb rmagick-2.16.0/doc/ex/m*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/n*.rb rmagick-2.16.0/doc/ex/o*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/pa*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/polaroid.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/polygon.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/polyline.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/posterize.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/preview.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/qbezierpath.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/quantize-m.rb rmagick-2.16.0/doc/ex/ra*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/rectangle.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/reduce_noise.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/remap.rb rmagick-2.16.0/doc/ex/res*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/ro*.rb rmagick-2.16.0/doc/ex/rubyname.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/rvg_linecap.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/rvg_opacity.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/rvg_stroke_dasharray.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/se*.rb rmagick-2.16.0/doc/ex/shade.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/shave.rb rmagick-2.16.0/doc/ex/shear.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/sk*.rb rmagick-2.16.0/doc/ex/smile.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/solarize.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/splice.rb rmagick-2.16.0/doc/ex/spread.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/st*.rb rmagick-2.16.0/doc/ex/swirl.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/text.rb rmagick-2.16.0/doc/ex/text_*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/texture*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/threshold.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/to_blob.rb rmagick-2.16.0/doc/ex/trans*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/unsharp_mask.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/v*.rb rmagick-2.16.0/doc/ex/wa*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/ex/wet_floor.rb rmagick-2.16.0/examples/c*.rb
REPLACE_RUBY+=	rmagick-2.16.0/examples/demo.rb rmagick-2.16.0/test/Image1.rb
REPLACE_RUBY+=	rmagick-2.16.0/test/Image2.rb rmagick-2.16.0/test/Image3.rb
REPLACE_RUBY+=	rmagick-2.16.0/test/ImageList1.rb
REPLACE_RUBY+=	rmagick-2.16.0/test/Image_attributes.rb
REPLACE_RUBY+=	rmagick-2.16.0/test/P*.rb rmagick-2.16.0/test/test_all_basic.rb
REPLACE_RUBY+=	rouge-3.3.0/bin/rougify ruby-openid-2.9.2/examples/discover
REPLACE_RUBY+=	ruby-openid-2.9.2/examples/rails_openid/public/dispatch.cgi
REPLACE_RUBY+=	ruby-openid-2.9.2/examples/rails_openid/public/dispatch.fcgi
REPLACE_RUBY+=	ruby-openid-2.9.2/examples/rails_openid/public/dispatch.rb
REPLACE_RUBY+=	ruby-openid-2.9.2/examples/rails_openid/script/rails
REPLACE_RUBY+=	rubyzip-1.2.3/samples/example.rb
REPLACE_RUBY+=	rubyzip-1.2.3/samples/example_filesystem.rb
REPLACE_RUBY+=	rubyzip-1.2.3/samples/gtk_ruby_zip.rb
REPLACE_RUBY+=	rubyzip-1.2.3/samples/qtzip.rb
REPLACE_RUBY+=	rubyzip-1.2.3/samples/write_simple.rb
REPLACE_RUBY+=	rubyzip-1.2.3/samples/zipfind.rb
REPLACE_RUBY+=	rubyzip-1.2.3/test/data/file2.txt
REPLACE_RUBY+=	rubyzip-1.2.3/test/data/notzippedruby.rb
REPLACE_RUBY+=	rubyzip-1.2.3/test/gentestfiles.rb sprockets-3.7.2/bin/sprockets
REPLACE_RUBY+=	thor-0.20.3/bin/thor
REPLACE_RUBY+=	thread_safe-0.3.6/examples/bench_cache.rb
REPLACE_RUBY+=	unicorn-5.5.3/GIT-VERSION-GEN unicorn-5.5.3/bin/unicorn*
REPLACE_RUBY+=	unicorn-5.5.3/t/bin/content-md5-put
REPLACE_RUBY+=	unicorn-5.5.3/t/bin/sha1sum.rb unicorn-5.5.3/t/bin/unused_listen
REPLACE_RUBY+=	unicorn-5.5.3/test/aggregate.rb yard-0.9.20/bin/yard
REPLACE_RUBY+=	yard-0.9.20/bin/yardoc yard-0.9.20/bin/yri

CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/rack-*/test/cgi/test.ru
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/json-2.2.0/json-java.gemspec
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/nokogiri-1.10.7/ports/patches/sort-patches-by-date
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/loofah-2.2.3/benchmark/benchmark.rb

# Selenium has Linux .so files.
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP=		no

# childprocess gem fix
SUBST_CLASSES+=		cproc
SUBST_FILES.cproc=	childprocess-2.0.0.gemspec
SUBST_MESSAGE.cproc=	Fixing chiildprocess gem.
SUBST_SED.cproc=	-e '/s\.extensions/d'
SUBST_STAGE.cproc=	pre-configure

SUBST_CLASSES+=		pkgcfg
SUBST_FILES.pkgcfg=	rmagick-2.16.0/ext/RMagick/extconf.rb
SUBST_MESSAGE.pkgcfg=	Fixing ImageMagick pkg-config paths.
SUBST_SED.pkgcfg=	-e 's|Magick-config|Magick-config6|g'
SUBST_SED.pkgcfg+=	-e 's|MagickWand-config|MagickWand-config6|g'
SUBST_SED.pkgcfg+=	-e 's|MagickWand`|MagickWand-6.Q16`|g'
SUBST_SED.pkgcfg+=	-e 's|MagickCore|MagickCore-6.Q16|g'
SUBST_STAGE.pkgcfg=	pre-configure

SUBST_CLASSES+=		rake
SUBST_STAGE.rake=	pre-configure
SUBST_MESSAGE.rake=	Replacing path to rake program.
SUBST_FILES.rake=	${DISTNAME}/Rakefile
SUBST_FILES.rake+=	ruby-openid-2.9.2/examples/rails_openid/Rakefile
SUBST_FILES.rake+=	simplecov-0.14.1/Rakefile
SUBST_SED.rake=		-e "s|/usr/bin/env rake|${PREFIX}/${RM_DIR}/gems/bin/rake|g"

SUBST_CLASSES+=		shell
SUBST_FILES.shell=	${DESTDIR}${PREFIX}/bin/redmine_*${RUBY_SUFFIX}.sh
SUBST_MESSAGE.shell=	Fixing paths in helper shell scripts.
SUBST_VARS.shell=	GEM PREFIX RUBY RUBY_PKGPREFIX RUBY_SUFFIX
SUBST_STAGE.shell=	post-install

REPLACE_BASH+=	mini_mime-1.0.2/bin/setup
REPLACE_BASH+=	mini_portile2-2.4.0/concourse/tasks/rake-test/task.sh
REPLACE_BASH+=	net-ldap-0.16.2/script/package net-ldap-0.16.2/script/release

GEM_HOME=	${RM_DIR}/gems
MESSAGE_SUBST+=	RM_DIR=${RM_DIR}
PLIST_SUBST+=	GEM_HOME=${GEM_HOME}

USE_LANGUAGES=	c

# Do not build internal libxml2 and libxslt.
MAKE_ENV+=	NOKOGIRI_USE_SYSTEM_LIBRARIES=yes
INSTALL_ENV+=	RM_DIR=${RM_DIR}
#		rake=${RUBYGEM_INSTALL_ROOT}/${PREFIX}/${GEM_HOME}/gems/rake-12.3.3/exe/rake
EGDIR=		${PREFIX}/share/examples/${RUBY_PKGPREFIX}-redmine

INSTALLATION_DIRS+=	bin ${EGDIR}/test ${RM_DIR}/app/.bundle \
			${RM_DIR}/app/config \
			${RM_DIR}/app/test/fixtures/configuration
RM_APP_CONFIG=		additional_environment.rb configuration.yml \
			database.yml
RM_TEST_CONFIG=		default.yml empty.yml no_default.yml overrides.yml

.for f in ${RM_APP_CONFIG}
CONF_FILES+=	${EGDIR}/${f}.example ${RM_DIR}/app/config/${f}
.endfor
.for f in ${RM_TEST_CONFIG}
CONF_FILES+=	${EGDIR}/test/${f}.example \
		${RM_DIR}/app/test/fixtures/configuration/${f}
.endfor

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_GROUP APACHE_USER RCD_SCRIPTS_DIR
FILES_SUBST+=	RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR} RM_DIR=${RM_DIR}
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER}

GEM_EXTSDIR_NEEDS_SUBDIR=	no

.include "../../lang/ruby/gem-extract.mk"

pre-configure:
	cd ${WRKSRC}/${DISTNAME} && ${CHMOD} -R g-w .

do-build:
.for gem in ${DISTFILES:M*.gem:S/.gem$//g}
	${RUN} cd ${WRKDIR}/${gem} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM_NAME} build ../${gem}.gemspec
	${RUN} ${TEST} -f ${WRKDIR}/${gem}/${gem}.gem || \
		${FAIL_MSG} "Build of ${gem}.gem failed."
.endfor

RUBYGEM_INSTALL_ROOT=		${WRKDIR}/.inst
RUBYGEM_INSTALL_ROOT_OPTION=	--install-root ${RUBYGEM_INSTALL_ROOT}
_RUBYGEM_OPTIONS=		--no-update-sources # don't cache the gem index
_RUBYGEM_OPTIONS+=		--install-dir ${PREFIX}/${GEM_HOME}
_RUBYGEM_OPTIONS+=		${RUBYGEM_INSTALL_ROOT_OPTION}
_RUBYGEM_OPTIONS+=		--ignore-dependencies
_RUBYGEM_OPTIONS+=		--no-document

do-install:
# Install gems
.for gem in ${DISTFILES:M*.gem:S/.gem$//g}
	@${STEP_MSG} "Installing gem into installation root"
	${RUN} ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} ${INSTALL_ENV} \
		${RUBYGEM_NAME} install --backtrace ${RUBYGEM_OPTIONS} \
			${_RUBYGEM_OPTIONS} --local ${WRKDIR}/${gem}/${gem}.gem
	@${STEP_MSG} "gem install"

	${RUN} cd ${RUBYGEM_INSTALL_ROOT}${PREFIX} && \
		pax -rwpp . ${DESTDIR}${PREFIX}
.endfor
# Install Redmine
	${INSTALL_DATA} ${FILESDIR}/bundle-config \
		${DESTDIR}${PREFIX}/${RM_DIR}/app/.bundle/config
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_migrate_plugins.sh \
		${DESTDIR}${PREFIX}/bin/redmine_migrate_plugins${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_generate_secret.sh \
		${DESTDIR}${PREFIX}/bin/redmine_generate_secret${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_migrate_db.sh \
		${DESTDIR}${PREFIX}/bin/redmine_migrate_db${RUBY_SUFFIX}.sh
	${INSTALL_DATA} ${FILESDIR}/Gemfile.lock \
		${DESTDIR}${PREFIX}/${RM_DIR}/app
	${INSTALL_DATA} ${FILESDIR}/secrets.yml \
		${DESTDIR}${PREFIX}/${RM_DIR}/app/config
	cd ${WRKDIR}/${DISTNAME} && pax -rw -pmp . \
		${DESTDIR}${PREFIX}/${RM_DIR}/app

post-install: unicorn-post-install
	find ${DESTDIR} -name .cvsignore -type f | xargs rm -rf
	find ${DESTDIR} -name .gitignore -type f | xargs rm -rf
	find ${DESTDIR} -name .hgignore -type f | xargs rm -rf
	find ${DESTDIR} -name ext -type d | xargs rm -rf
	find ${DESTDIR} -name mkmf.log -type f | xargs rm -rf
	find ${DESTDIR} -name gem_make.out -type f | xargs rm -rf
.for f in ${RM_APP_CONFIG}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/config/${f}.example \
		${DESTDIR}/${EGDIR}
.endfor
.for f in ${RM_TEST_CONFIG}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/test/fixtures/configuration/${f}.example \
		${DESTDIR}/${EGDIR}/test
.endfor
	find ${DESTDIR}${PREFIX}/share/${RUBY_PKGPREFIX}-redmine -type f -print0 \
		| xargs -0 chmod g+r,g-w,-x,o-w
	find ${DESTDIR}${PREFIX}/share/${RUBY_PKGPREFIX}-redmine -type d -print0 \
		| xargs -0 chmod g-w

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
