// Automatically created from `interface.cc.tmp' by glade-filter.awk

#include <unistd-jigdo.h>
#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <config.h>
#include <gtk/gtk.h>

namespace GUI {

  struct Window {
    GtkWidget* create();
    GtkWidget *window;
    GtkWidget *windowVbox;
    GtkWidget *toolbarHandle;
    GtkWidget *toolbar;
    GtkIconSize tmp_toolbar_icon_size;
    GtkWidget *toolbarOpen;
    GtkWidget *toolbarReuse;
    GtkWidget *toolbarSettings;
    GtkWidget *toolbarExit;
    GtkWidget *windowPaned;
    GtkWidget *invisibleNotebook;
    GtkWidget *pageOpen;
    GtkWidget *aboutJigdoLogo;
    AtkObject *atko;
    GtkWidget *aboutBgnd;
    GtkWidget *aboutJigdoLabel;
    GtkWidget *aboutJigdoButton;
    GtkWidget *aboutJigdoButtonLabel;
    GtkWidget *openButton;
    GtkWidget *open_sourceURLLabel;
    GtkWidget *open_destinationLabel;
    GtkWidget *open_URL;
    GtkWidget *open_dest;
    GtkWidget *open_URLSel;
    GtkWidget *open_destSel;
    GtkWidget *enterUrlLabel;
    GtkWidget *pageOpenLabel;
    GtkWidget *pageReuse;
    GtkWidget *reuse_path;
    GtkWidget *reuse_pathSel;
    GtkWidget *reuse_scanButton;
    GtkWidget *reuse_clearButton;
    GtkWidget *pageReuseLabel;
    GtkWidget *pageDownload;
    GtkWidget *download_buttonInfo;
    GtkWidget *download_closeButton;
    GtkWidget *download_restartButton;
    GtkWidget *download_stopButton;
    GtkWidget *download_pauseButton;
    GtkWidget *download_startButton;
    GtkWidget *download_dest;
    GtkWidget *download_progress;
    GtkWidget *download_status;
    GtkWidget *download_URL;
    GtkWidget *pageDownloadLabel;
    GtkWidget *pageJigdo;
    GtkWidget *jigdo_InfoVbox;
    GtkWidget *jigdo_ShortInfo;
    GtkWidget *jigdo_Info;
    GSList *radiobutton1_group ;
    GtkWidget *combo_entry1;
    GtkWidget *combo_entry2;
    GtkWidget *combo_entry3;
    GtkWidget *jigdo_buttonInfo;
    GtkWidget *jigdo_closeButton;
    GtkWidget *jigdo_restartButton;
    GtkWidget *jigdo_stopButton;
    GtkWidget *jigdo_pauseButton;
    GtkWidget *jigdo_startButton;
    GtkWidget *jigdo_status;
    GtkWidget *jigdo_progress;
    GtkWidget *jigdo_dest;
    GtkWidget *jigdo_URL;
    GtkWidget *pageJigdoLabel;
    GtkWidget *progressScroll;
    GtkWidget *jobs;
    GtkTooltips *tooltips;
  };

  struct Filesel {
    GtkWidget* create();
    GtkWidget *filesel;
    GtkWidget *okButton;
    GtkWidget *cancelButton;
  };

  struct Settings {
    GtkWidget* create();
    GtkWidget *settings;
    GtkObject *spinbutton2_adj;
    GtkObject *spinbutton3_adj;
    GtkTooltips *tooltips;
  };

  struct License {
    GtkWidget* create();
    GtkWidget *license;
    GtkWidget *licenseScroll;
    GtkWidget *licenseText;
  };

} // namespace GUI

#endif /* INTERFACE_HH */
