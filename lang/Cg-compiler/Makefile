# $NetBSD: Makefile,v 1.18 2015/12/30 02:59:07 dholland Exp $
#

DISTNAME=	Cg-3.1_April2012_x86${DIST_ARCH}
PKGNAME=	${DISTNAME:S/-/-compiler-/:S/_April2012_x86${DIST_ARCH}//}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://developer.download.nvidia.com/cg/Cg_3.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://developer.nvidia.com/cg-toolkit
COMMENT=	Compiler for the Cg 3.1 language
LICENSE=	nvidia-license

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base
EMUL_REQD=		suse>=7.3

BUILD_DIRS=		# empty
RUN_LDCONFIG=		yes
USE_TOOLS+=		pax

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		PLIST.common
.if ${EMUL_ARCH} == "i386"
  DIST_ARCH=		# blank
  INSTALLATION_DIRS=	${EMULDIR}/lib
  PLIST_SRC+=		PLIST.linux-i386
.elif ${EMUL_ARCH} == "x86_64"
  DIST_ARCH=		_64
  INSTALLATION_DIRS=	${EMULDIR}/lib64
  PLIST_SRC+=		PLIST.linux-x86_64
.else
  DIST_ARCH=		# blank
  INSTALLATION_DIRS=	${EMULDIR}/lib
  PLIST_SRC+=		PLIST.linux-i386
.endif

INSTALLATION_DIRS+=	bin include/Cg share/doc/Cg-compiler \
			share/doc/Cg-compiler/html \
			share/examples/Cg-compiler/Direct3D10/advanced/cgfx_buffer_lighting \
			share/examples/Cg-compiler/Direct3D10/advanced/combine_programs \
			share/examples/Cg-compiler/Direct3D10/advanced/custom_state_assignments \
			share/examples/Cg-compiler/Direct3D10/advanced/gs_shrinky \
			share/examples/Cg-compiler/Direct3D10/advanced/gs_simple \
			share/examples/Cg-compiler/Direct3D10/advanced/include_string \
			share/examples/Cg-compiler/Direct3D10/advanced/interpolation_modifier \
			share/examples/Cg-compiler/Direct3D10/basic/02_vertex_and_fragment_program \
			share/examples/Cg-compiler/Direct3D10/basic/03_uniform_parameter \
			share/examples/Cg-compiler/Direct3D10/basic/04_varying_parameter \
			share/examples/Cg-compiler/Direct3D10/basic/05_texture_sampling \
			share/examples/Cg-compiler/Direct3D10/basic/06_vertex_twisting \
			share/examples/Cg-compiler/Direct3D10/basic/07_two_texture_accesses \
			share/examples/Cg-compiler/Direct3D10/basic/cgfx_buffer \
			share/examples/Cg-compiler/Direct3D10/basic/cgfx_simple \
			share/examples/Cg-compiler/Direct3D10/basic/cgfx_texture \
			share/examples/Cg-compiler/Direct3D10/miniDXUT \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_buffer_lighting \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_bumpdemo_array \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_bumpdemo \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_latest \
			share/examples/Cg-compiler/Direct3D11/advanced/combine_programs \
			share/examples/Cg-compiler/Direct3D11/advanced/custom_state_assignments \
			share/examples/Cg-compiler/Direct3D11/advanced/gs_shrinky \
			share/examples/Cg-compiler/Direct3D11/advanced/gs_simple \
			share/examples/Cg-compiler/Direct3D11/advanced/include_string \
			share/examples/Cg-compiler/Direct3D11/advanced/interpolation_modifier \
			share/examples/Cg-compiler/Direct3D11/basic/02_vertex_and_fragment_program \
                        share/examples/Cg-compiler/Direct3D11/basic/03_uniform_parameter \
                        share/examples/Cg-compiler/Direct3D11/basic/04_varying_parameter \
                        share/examples/Cg-compiler/Direct3D11/basic/05_texture_sampling \
                        share/examples/Cg-compiler/Direct3D11/basic/06_vertex_twisting \
                        share/examples/Cg-compiler/Direct3D11/basic/07_two_texture_accesses \
                        share/examples/Cg-compiler/Direct3D11/basic/cgfx_buffer \
                        share/examples/Cg-compiler/Direct3D11/basic/cgfx_simple \
                        share/examples/Cg-compiler/Direct3D11/basic/cgfx_texture \
			share/examples/Cg-compiler/Direct3D9/advanced/cgfx_buffer_lighting \
                        share/examples/Cg-compiler/Direct3D9/advanced/cgfx_bumpdemo \
			share/examples/Cg-compiler/Direct3D9/basic/01_vertex_program \
			share/examples/Cg-compiler/Direct3D9/basic/02_vertex_and_fragment_program \
                        share/examples/Cg-compiler/Direct3D9/basic/03_uniform_parameter \
                        share/examples/Cg-compiler/Direct3D9/basic/04_varying_parameter \
                        share/examples/Cg-compiler/Direct3D9/basic/05_texture_sampling \
                        share/examples/Cg-compiler/Direct3D9/basic/06_vertex_twisting \
                        share/examples/Cg-compiler/Direct3D9/basic/07_two_texture_accesses \
			share/examples/Cg-compiler/Direct3D9/miniDXUT \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_boxfilter \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_bumpdemo_array \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_bumpdemo \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_interfaces \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_latest \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_procfx \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_texture_array \
			share/examples/Cg-compiler/OpenGL/advanced/combine_program \
			share/examples/Cg-compiler/OpenGL/advanced/custom_state_assignments \
			share/examples/Cg-compiler/OpenGL/advanced/generic_attribs \
			share/examples/Cg-compiler/OpenGL/advanced/gs_interp_quad \
			share/examples/Cg-compiler/OpenGL/advanced/gs_md2render \
			share/examples/Cg-compiler/OpenGL/advanced/gs_quadnormal \
			share/examples/Cg-compiler/OpenGL/advanced/gs_shrinky \
			share/examples/Cg-compiler/OpenGL/advanced/gs_simple \
			share/examples/Cg-compiler/OpenGL/advanced/include_string \
			share/examples/Cg-compiler/OpenGL/advanced/interpolation_modifier \
			share/examples/Cg-compiler/OpenGL/advanced/texture_array \
			share/examples/Cg-compiler/OpenGL/advanced/vertex_texture \
			share/examples/Cg-compiler/OpenGL/basic/01_vertex_program \
			share/examples/Cg-compiler/OpenGL/basic/02_vertex_and_fragment_program \
			share/examples/Cg-compiler/OpenGL/basic/03_uniform_parameter \
			share/examples/Cg-compiler/OpenGL/basic/04_varying_parameter \
			share/examples/Cg-compiler/OpenGL/basic/05_texture_sampling \
			share/examples/Cg-compiler/OpenGL/basic/06_vertex_twisting \
			share/examples/Cg-compiler/OpenGL/basic/07_two_texture_accesses \
			share/examples/Cg-compiler/OpenGL/basic/08_vertex_transform \
			share/examples/Cg-compiler/OpenGL/basic/09_vertex_lighting \
			share/examples/Cg-compiler/OpenGL/basic/10_fragment_lighting \
			share/examples/Cg-compiler/OpenGL/basic/11_two_lights_with_structs \
			share/examples/Cg-compiler/OpenGL/basic/12_light_attenuation \
			share/examples/Cg-compiler/OpenGL/basic/13_spotlight \
			share/examples/Cg-compiler/OpenGL/basic/14_bulge \
			share/examples/Cg-compiler/OpenGL/basic/15_particle_system \
			share/examples/Cg-compiler/OpenGL/basic/16_keyframe_interpolation \
			share/examples/Cg-compiler/OpenGL/basic/18_cube_map_reflection \
			share/examples/Cg-compiler/OpenGL/basic/19_cube_map_refraction \
			share/examples/Cg-compiler/OpenGL/basic/20_chromatic_dispersion \
			share/examples/Cg-compiler/OpenGL/basic/21_bump_map_wall \
			share/examples/Cg-compiler/OpenGL/basic/22_specular_bump_map \
			share/examples/Cg-compiler/OpenGL/basic/23_bump_map_floor \
			share/examples/Cg-compiler/OpenGL/basic/24_bump_map_torus \
			share/examples/Cg-compiler/OpenGL/basic/25_uniform_fog \
			share/examples/Cg-compiler/OpenGL/basic/26_toon_shading \
			share/examples/Cg-compiler/OpenGL/basic/27_projective_texturing \
			share/examples/Cg-compiler/OpenGL/buffers/buffer_lighting \
			share/examples/Cg-compiler/OpenGL/buffers/cgfx_buffer_lighting \
			share/examples/Cg-compiler/OpenGL/buffers/ubo_lighting \
			share/examples/Cg-compiler/OpenGL/glew/include/GL \
			share/examples/Cg-compiler/OpenGL/glew/src \
			share/examples/Cg-compiler/OpenGL/tessellation/cgfx_tessellation \
			share/examples/Cg-compiler/OpenGL/tessellation/phong_tess \
			share/examples/Cg-compiler/OpenGL/tessellation/pn_triangles \
			share/examples/Cg-compiler/OpenGL/tessellation/quad_tri_bezier \
			share/examples/Cg-compiler/OpenGL/tessellation/terrain_tess \
			share/examples/Cg-compiler/OpenGL/tessellation/tess_bezier \
			share/examples/Cg-compiler/OpenGL/tessellation/tess_simple \
			share/examples/Cg-compiler/Tools/cgfxcat \
			share/examples/Cg-compiler/Tools/cginfo \
			share/examples/Cg-compiler/Trace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/* ${DESTDIR}${PREFIX}/bin
.if ${EMUL_ARCH} == "i386"
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${DESTDIR}${EMULDIR}/lib
.elif ${EMUL_ARCH} == "x86_64"
	${INSTALL_DATA} ${WRKSRC}/usr/lib64/* ${DESTDIR}${EMULDIR}/lib64
.else
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${DESTDIR}${EMULDIR}/lib
.endif
	${INSTALL_DATA} ${WRKSRC}/usr/include/Cg/* \
		${DESTDIR}${PREFIX}/include/Cg
	${INSTALL_DATA} ${WRKSRC}/usr/local/Cg/README ${DESTDIR}${PREFIX}/share/doc/Cg-compiler
	${INSTALL_DATA} ${WRKSRC}/usr/local/Cg/docs/Cg* ${DESTDIR}${PREFIX}/share/doc/Cg-compiler
	${INSTALL_DATA} ${WRKSRC}/usr/local/Cg/docs/html/* ${DESTDIR}${PREFIX}/share/doc/Cg-compiler/html
	cd ${WRKSRC}/usr/local/Cg/examples && \
		${INSTALL_DATA} Direct3D10/advanced/Direct3D10_Advanced_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced && \
		${INSTALL_DATA} Direct3D10/advanced/cgfx_buffer_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced/cgfx_buffer_lighting && \
		${INSTALL_DATA} Direct3D10/advanced/combine_programs/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced/combine_programs && \
		${INSTALL_DATA} Direct3D10/advanced/custom_state_assignments/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced/custom_state_assignments && \
		${INSTALL_DATA} Direct3D10/advanced/gs_shrinky/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced/gs_shrinky && \
		${INSTALL_DATA} Direct3D10/advanced/gs_simple/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced/gs_simple && \
		${INSTALL_DATA} Direct3D10/advanced/include_string/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced/include_string && \
		${INSTALL_DATA} Direct3D10/advanced/interpolation_modifier/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/advanced/interpolation_modifier && \
		${INSTALL_DATA} Direct3D10/basic/Direct3D10_Basic_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic && \
		${INSTALL_DATA} Direct3D10/basic/02_vertex_and_fragment_program/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/02_vertex_and_fragment_program && \
		${INSTALL_DATA} Direct3D10/basic/03_uniform_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/03_uniform_parameter && \
		${INSTALL_DATA} Direct3D10/basic/04_varying_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/04_varying_parameter && \
		${INSTALL_DATA} Direct3D10/basic/05_texture_sampling/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/05_texture_sampling && \
		${INSTALL_DATA} Direct3D10/basic/06_vertex_twisting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/06_vertex_twisting && \
		${INSTALL_DATA} Direct3D10/basic/07_two_texture_accesses/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/07_two_texture_accesses && \
		${INSTALL_DATA} Direct3D10/basic/cgfx_buffer/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/cgfx_buffer && \
		${INSTALL_DATA} Direct3D10/basic/cgfx_simple/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/cgfx_simple && \
		${INSTALL_DATA} Direct3D10/basic/cgfx_texture/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/basic/cgfx_texture && \
		${INSTALL_DATA} Direct3D10/miniDXUT/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D10/miniDXUT && \
		${INSTALL_DATA} Direct3D11/advanced/Direct3D11_Advanced_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced && \
		${INSTALL_DATA} Direct3D11/advanced/cgfx_buffer_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/cgfx_buffer_lighting && \
		${INSTALL_DATA} Direct3D11/advanced/cgfx_bumpdemo_array/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/cgfx_bumpdemo_array && \
		${INSTALL_DATA} Direct3D11/advanced/cgfx_bumpdemo/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/cgfx_bumpdemo && \
		${INSTALL_DATA} Direct3D11/advanced/cgfx_latest/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/cgfx_latest && \
		${INSTALL_DATA} Direct3D11/advanced/combine_programs/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/combine_programs && \
		${INSTALL_DATA} Direct3D11/advanced/custom_state_assignments/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/custom_state_assignments && \
		${INSTALL_DATA} Direct3D11/advanced/gs_shrinky/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/gs_shrinky && \
		${INSTALL_DATA} Direct3D11/advanced/gs_simple/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/gs_simple && \
		${INSTALL_DATA} Direct3D11/advanced/include_string/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/include_string && \
		${INSTALL_DATA} Direct3D11/advanced/interpolation_modifier/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/advanced/interpolation_modifier && \
		${INSTALL_DATA} Direct3D11/basic/Direct3D11_Basic_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic && \
		${INSTALL_DATA} Direct3D11/basic/02_vertex_and_fragment_program/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/02_vertex_and_fragment_program && \
		${INSTALL_DATA} Direct3D11/basic/03_uniform_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/03_uniform_parameter && \
		${INSTALL_DATA} Direct3D11/basic/04_varying_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/04_varying_parameter && \
		${INSTALL_DATA} Direct3D11/basic/05_texture_sampling/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/05_texture_sampling && \
		${INSTALL_DATA} Direct3D11/basic/06_vertex_twisting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/06_vertex_twisting && \
		${INSTALL_DATA} Direct3D11/basic/07_two_texture_accesses/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/07_two_texture_accesses && \
		${INSTALL_DATA} Direct3D11/basic/cgfx_buffer/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/cgfx_buffer && \
		${INSTALL_DATA} Direct3D11/basic/cgfx_simple/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/cgfx_simple && \
		${INSTALL_DATA} Direct3D11/basic/cgfx_texture/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D11/basic/cgfx_texture && \
		${INSTALL_DATA} Direct3D9/advanced/Direct3D9_Advanced_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/advanced && \
		${INSTALL_DATA} Direct3D9/advanced/cgfx_buffer_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/advanced/cgfx_buffer_lighting && \
		${INSTALL_DATA} Direct3D9/advanced/cgfx_bumpdemo/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/advanced/cgfx_bumpdemo && \
		${INSTALL_DATA} Direct3D9/basic/Direct3D9_Basic_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic && \
		${INSTALL_DATA} Direct3D9/basic/01_vertex_program/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic/01_vertex_program && \
		${INSTALL_DATA} Direct3D9/basic/02_vertex_and_fragment_program/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic/02_vertex_and_fragment_program && \
		${INSTALL_DATA} Direct3D9/basic/03_uniform_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic/03_uniform_parameter && \
		${INSTALL_DATA} Direct3D9/basic/04_varying_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic/04_varying_parameter && \
		${INSTALL_DATA} Direct3D9/basic/05_texture_sampling/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic/05_texture_sampling && \
		${INSTALL_DATA} Direct3D9/basic/06_vertex_twisting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic/06_vertex_twisting && \
		${INSTALL_DATA} Direct3D9/basic/07_two_texture_accesses/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/basic/07_two_texture_accesses && \
		${INSTALL_DATA} Direct3D9/miniDXUT/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Direct3D9/miniDXUT && \
		${INSTALL_DATA} OpenGL/Makefile \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL && \
		${INSTALL_DATA} OpenGL/advanced/Makefile \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced && \
		${INSTALL_DATA} OpenGL/advanced/OpenGL_Advanced_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced && \
		${INSTALL_DATA} OpenGL/advanced/cgfx_boxfilter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/cgfx_boxfilter && \
		${INSTALL_DATA} OpenGL/advanced/cgfx_bumpdemo_array/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/cgfx_bumpdemo_array && \
		${INSTALL_DATA} OpenGL/advanced/cgfx_bumpdemo/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/cgfx_bumpdemo && \
		${INSTALL_DATA} OpenGL/advanced/cgfx_interfaces/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/cgfx_interfaces && \
		${INSTALL_DATA} OpenGL/advanced/cgfx_latest/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/cgfx_latest && \
		${INSTALL_DATA} OpenGL/advanced/cgfx_procfx/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/cgfx_procfx && \
		${INSTALL_DATA} OpenGL/advanced/cgfx_texture_array/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/cgfx_texture_array && \
		${INSTALL_DATA} OpenGL/advanced/combine_program/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/combine_program && \
		${INSTALL_DATA} OpenGL/advanced/custom_state_assignments/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/custom_state_assignments && \
		${INSTALL_DATA} OpenGL/advanced/generic_attribs/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/generic_attribs && \
		${INSTALL_DATA} OpenGL/advanced/gs_interp_quad/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/gs_interp_quad && \
		${INSTALL_DATA} OpenGL/advanced/gs_md2render/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/gs_md2render && \
		${INSTALL_DATA} OpenGL/advanced/gs_quadnormal/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/gs_quadnormal && \
		${INSTALL_DATA} OpenGL/advanced/gs_shrinky/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/gs_shrinky && \
		${INSTALL_DATA} OpenGL/advanced/gs_simple/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/gs_simple && \
		${INSTALL_DATA} OpenGL/advanced/include_string/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/include_string && \
		${INSTALL_DATA} OpenGL/advanced/interpolation_modifier/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/interpolation_modifier && \
		${INSTALL_DATA} OpenGL/advanced/texture_array/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/texture_array && \
		${INSTALL_DATA} OpenGL/advanced/vertex_texture/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/advanced/vertex_texture && \
		${INSTALL_DATA} OpenGL/basic/Makefile \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic && \
		${INSTALL_DATA} OpenGL/basic/OpenGL_Basic_* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic && \
		${INSTALL_DATA} OpenGL/basic/01_vertex_program/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/01_vertex_program && \
		${INSTALL_DATA} OpenGL/basic/02_vertex_and_fragment_program/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/02_vertex_and_fragment_program && \
		${INSTALL_DATA} OpenGL/basic/03_uniform_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/03_uniform_parameter && \
		${INSTALL_DATA} OpenGL/basic/04_varying_parameter/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/04_varying_parameter && \
		${INSTALL_DATA} OpenGL/basic/05_texture_sampling/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/05_texture_sampling && \
		${INSTALL_DATA} OpenGL/basic/06_vertex_twisting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/06_vertex_twisting && \
		${INSTALL_DATA} OpenGL/basic/07_two_texture_accesses/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/07_two_texture_accesses && \
		${INSTALL_DATA} OpenGL/basic/08_vertex_transform/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/08_vertex_transform && \
		${INSTALL_DATA} OpenGL/basic/09_vertex_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/09_vertex_lighting && \
		${INSTALL_DATA} OpenGL/basic/10_fragment_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/10_fragment_lighting && \
		${INSTALL_DATA} OpenGL/basic/11_two_lights_with_structs/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/11_two_lights_with_structs && \
		${INSTALL_DATA} OpenGL/basic/12_light_attenuation/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/12_light_attenuation && \
		${INSTALL_DATA} OpenGL/basic/13_spotlight/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/13_spotlight && \
		${INSTALL_DATA} OpenGL/basic/14_bulge/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/14_bulge && \
		${INSTALL_DATA} OpenGL/basic/15_particle_system/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/15_particle_system && \
		${INSTALL_DATA} OpenGL/basic/16_keyframe_interpolation/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/16_keyframe_interpolation && \
		${INSTALL_DATA} OpenGL/basic/18_cube_map_reflection/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/18_cube_map_reflection && \
		${INSTALL_DATA} OpenGL/basic/19_cube_map_refraction/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/19_cube_map_refraction && \
		${INSTALL_DATA} OpenGL/basic/20_chromatic_dispersion/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/20_chromatic_dispersion && \
		${INSTALL_DATA} OpenGL/basic/21_bump_map_wall/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/21_bump_map_wall && \
		${INSTALL_DATA} OpenGL/basic/22_specular_bump_map/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/22_specular_bump_map && \
		${INSTALL_DATA} OpenGL/basic/23_bump_map_floor/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/23_bump_map_floor && \
		${INSTALL_DATA} OpenGL/basic/24_bump_map_torus/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/24_bump_map_torus && \
		${INSTALL_DATA} OpenGL/basic/25_uniform_fog/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/25_uniform_fog && \
		${INSTALL_DATA} OpenGL/basic/26_toon_shading/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/26_toon_shading && \
		${INSTALL_DATA} OpenGL/basic/27_projective_texturing/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/basic/27_projective_texturing && \
		${INSTALL_DATA} OpenGL/buffers/Makefile \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/buffers && \
		${INSTALL_DATA} OpenGL/buffers/OpenGL_Buffers_20* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/buffers && \
		${INSTALL_DATA} OpenGL/buffers/buffer_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/buffers/buffer_lighting && \
		${INSTALL_DATA} OpenGL/buffers/cgfx_buffer_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/buffers/cgfx_buffer_lighting && \
		${INSTALL_DATA} OpenGL/buffers/ubo_lighting/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/buffers/ubo_lighting && \
		${INSTALL_DATA} OpenGL/glew/LICENSE.txt \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/glew && \
		${INSTALL_DATA} OpenGL/glew/Makefile* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/glew && \
		${INSTALL_DATA} OpenGL/glew/include/GL/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/glew/include/GL && \
		${INSTALL_DATA} OpenGL/glew/glew* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/glew && \
		${INSTALL_DATA} OpenGL/glew/src/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/glew/src && \
		${INSTALL_DATA} OpenGL/glew/visualinfo* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/glew/ && \
		${INSTALL_DATA} OpenGL/tessellation/Makefile \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/ && \
		${INSTALL_DATA} OpenGL/tessellation/*.sln \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/ && \
		${INSTALL_DATA} OpenGL/tessellation/cgfx_tessellation/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/cgfx_tessellation && \
		${INSTALL_DATA} OpenGL/tessellation/phong_tess/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/phong_tess && \
		${INSTALL_DATA} OpenGL/tessellation/pn_triangles/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/pn_triangles && \
		${INSTALL_DATA} OpenGL/tessellation/quad_tri_bezier/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/quad_tri_bezier && \
		${INSTALL_DATA} OpenGL/tessellation/terrain_tess/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/terrain_tess && \
		${INSTALL_DATA} OpenGL/tessellation/tess_bezier/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/tess_bezier && \
		${INSTALL_DATA} OpenGL/tessellation/tess_simple/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/OpenGL/tessellation/tess_simple && \
		${INSTALL_DATA} README \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler && \
		${INSTALL_DATA} Tools/Makefile \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Tools && \
		${INSTALL_DATA} Tools/*.sln \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Tools && \
		${INSTALL_DATA} Tools/cgfxcat/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Tools/cgfxcat && \
		${INSTALL_DATA} Tools/cginfo/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Tools/cginfo && \
		${INSTALL_DATA} Trace/* \
			${DESTDIR}${PREFIX}/share/examples/Cg-compiler/Trace

.include "../../mk/bsd.pkg.mk"
