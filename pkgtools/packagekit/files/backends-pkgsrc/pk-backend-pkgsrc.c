/* $NetBSD: pk-backend-pkgsrc.c,v 1.1.1.1 2009/01/08 00:21:01 jmcneill Exp $ */

#include <packagekit-glib/packagekit.h>
#include <pk-backend.h>
#include <pk-backend-spawn.h>

static PkBackendSpawn *spawn = NULL;

static void
backend_initialize(PkBackend *backend)
{
	spawn = pk_backend_spawn_new();
	pk_backend_spawn_set_name(spawn, "pkgsrc");
}

static void
backend_destroy(PkBackend *backend)
{
	g_object_unref(spawn);
}

static PkBitfield
backend_get_groups(PkBackend *backend)
{
	return pk_bitfield_from_enums(
	    PK_GROUP_ENUM_ACCESSORIES,
	    PK_GROUP_ENUM_ADMIN_TOOLS,
	    PK_GROUP_ENUM_COMMUNICATION,
	    PK_GROUP_ENUM_DESKTOP_GNOME,
	    PK_GROUP_ENUM_DESKTOP_KDE,
	    PK_GROUP_ENUM_FONTS,
	    PK_GROUP_ENUM_GAMES,
	    PK_GROUP_ENUM_GRAPHICS,
	    PK_GROUP_ENUM_INTERNET,
	    PK_GROUP_ENUM_MULTIMEDIA,
	    PK_GROUP_ENUM_NETWORK,
	    PK_GROUP_ENUM_OTHER,
	    PK_GROUP_ENUM_PROGRAMMING,
	    PK_GROUP_ENUM_SECURITY,
	    -1);
}

static PkBitfield
backend_get_filters(PkBackend *backend)
{
	return pk_bitfield_from_enums(
	    PK_FILTER_ENUM_GUI,
	    PK_FILTER_ENUM_INSTALLED,
	    PK_FILTER_ENUM_DEVELOPMENT,
	    -1);
}

static void
backend_cancel(PkBackend *backend)
{
	pk_backend_spawn_kill(spawn);
}

static void
backend_get_details(PkBackend *backend, gchar **package_ids)
{
	gchar *package_ids_temp;
	package_ids_temp = pk_package_ids_to_text(package_ids);
	pk_backend_spawn_helper(spawn, "pkgsrc-backend.sh", "get-details", package_ids_temp, NULL);
	g_free(package_ids_temp);
}

static void
backend_get_packages(PkBackend *backend, PkBitfield filters)
{
	gchar *filters_temp;
	filters_temp = pk_filter_bitfield_to_text(filters);
	pk_backend_spawn_helper(spawn, "pkgsrc-backend.sh", "get-packages", filters_temp, NULL);
	g_free(filters_temp);
}

static void
backend_get_repo_list(PkBackend *backend, PkBitfield filters)
{
	pk_backend_set_status(backend, PK_STATUS_ENUM_QUERY);
	/* TODO */
	pk_backend_repo_detail(backend, "pkgsrc", "NetBSD 5.0 (pkgsrc-2008Q4)", TRUE);
	pk_backend_finished (backend);
}

static void
backend_resolve(PkBackend *backend, PkBitfield filters, gchar **package_ids)
{
	gchar *package_ids_temp;
	gchar *filters_temp;
	filters_temp = pk_filter_bitfield_to_text(filters);
	package_ids_temp = pk_package_ids_to_text(package_ids);
	pk_backend_spawn_helper(spawn, "pkgsrc-backend.sh", "resolve", filters_temp, package_ids_temp, NULL);
	g_free(package_ids_temp);
	g_free(filters_temp);
}

static void
backend_search_group(PkBackend *backend, PkBitfield filters, const gchar *search)
{
	gchar *filters_temp;
	filters_temp = pk_filter_bitfield_to_text(filters); 
	pk_backend_spawn_helper(spawn, "pkgsrc-backend.sh", "search-group", filters_temp, search, NULL);
	g_free(filters_temp);
}

PK_BACKEND_OPTIONS(
	"pkgsrc",				/* description */
	"The NetBSD Packages Collection <packages@NetBSD.org>", 	/* author */
	backend_initialize,			/* initalize */
	backend_destroy,			/* destroy */
	backend_get_groups,			/* get_groups */
	backend_get_filters,			/* get_filters */
	NULL,					/* get_mime_types */
	backend_cancel,				/* cancel */
	NULL,					/* download_packages */
	NULL,					/* get_categories */
	NULL,					/* get_depends */
	backend_get_details,			/* get_details */
	NULL,					/* get_distro_upgrades */
	NULL,					/* get_files */
	backend_get_packages,			/* get_packages */
	backend_get_repo_list,			/* get_repo_list */
	NULL,					/* get_requires */
	NULL,					/* get_update_detail */
	NULL,					/* get_updates */
	NULL,					/* install_files */
	NULL,					/* install_packages */
	NULL,					/* install_signature */
	NULL,					/* refresh_cache */
	NULL,					/* remove_packages */
	NULL,					/* repo_enable */
	NULL,					/* repo_set_data */
	backend_resolve,			/* resolve */
	NULL,					/* rollback */
	NULL,					/* search_details */
	NULL,					/* search_file */
	backend_search_group,			/* search_group */
	NULL,					/* search_name */
	NULL,					/* update_packages */
	NULL,					/* update_system */
	NULL					/* what_provides */
);
